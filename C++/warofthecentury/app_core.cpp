#include "app_core.hpp"

#include <sstream>    // for to_string
#include <filesystem> // for checking our bin folder.

namespace game
{
	namespace engine
	{
		std::string getUserInput()
		{
			std::string userInput;
			getline(std::cin, userInput);

			if (userInput[0] == '!')
			{
				//debug commands
			}

			logger("user: " + userInput);

			return userInput;
		}

		template<typename T>
		std::string to_string(const T& value)
		{
			std::ostringstream oss;
			oss << value;
			return oss.str();
		}

		int randomNumberGenerator(int percentNumber)
		{
			srand((unsigned int)time(NULL));
			unsigned int randomNumber = rand() % percentNumber;

			if (randomNumber == 0)
			{
				randomNumber = randomNumber + 1;
			}

			return randomNumber;
		}

		void wait_for(int mseconds)
		{
			clock_t goal = mseconds + clock();
			while (goal > clock());
		}

		void clear_screen()
		{
			#ifdef _WIN32
			#define CLEAR "cls"
			#else //In any other OS
			#define CLEAR "clear"
			#endif

			system(CLEAR);
		}

		void pause()
		{
			std::cout << "press enter to continue"; std::cin.get();
		}

		void logger(std::string output)
		{
			//writes to the file "app.log"
			std::ofstream log("bin\\app.log", std::ios::app);

			if (log.is_open()) // if we can't open the output streeam
			{
				log << output << std::endl;

				if (log.bad())
				{
					std::cerr << "failed to write to log!" << std::endl;
				}

				log.close();
			}
			else
			{
				std::cerr << "\n" << "unable to open file 'app.log'" << std::endl;
			} // or we can auto close, but nah
		}

		void errorReporter(std::string errorType, std::string location)
		{
			if (errorType == "internal")
			{
				std::string internalError("something went terribly wrong at" " ");
		
				std::cerr << internalError << location << std::endl;
		
				logger((internalError + location));
			}
			else // normally we would call internal error here!
			{
				std::cerr << "this should never happen, if it does, talk to Wyatt." << std::endl;
				logger(("this error shouldn't have happened, but it did, at" + location));
			}
		}

		void prepare_engine()
		{
			namespace filesystem = std::experimental::filesystem; //Vertexwahn I love you.

			if (!filesystem::exists("bin"))
			{
				filesystem::create_directory("bin");
			}
		
			engine::logger("---new session---");		
			engine::logger("engine is ready.");
		}
	}

	namespace ply
	{
		short health;
		bool dead(false);
		std::string name;

		void damage(int amount)
		{
			health =- amount;

			if (health <= 0)
			{
				dead = true;
			}

			std::string amount_log = engine::to_string(amount); std::string health_text = engine::to_string(health);
			engine::logger(("player lost " + amount_log + " health and now has " + health_text + "health"));
		}

		void heal(int amount)
		{
			health =+ amount;

			if (health > 100)
			{
				health = 100;
			}

			std::string amount_log = engine::to_string(amount); std::string health_text = engine::to_string(health);
			engine::logger(("player was healed " + amount_log + " health and now has " + health_text + " health"));
		}

		void set_health(int amount)
		{
			health = amount;

			std::string amount_log = engine::to_string(amount);
			engine::logger(("player health set to " + amount_log));
		}
	}

	void pre_game_setup()
	{
		engine::logger("checking if new player...");

		std::ifstream first_time("bin\\settings.dat");

		std::string $first_time;

		while (first_time >> $first_time); // set whatever is on the first line to $first_time

		if ($first_time == "first_time=true") // if we are new.
		{
			engine::logger("new player, opening main menu.");

			main_menu("new_game");
		}
		else if ($first_time == "first_time=false") // if we aren't new
		{
			engine::logger("not a new player, opening main menu.");

			main_menu("continue");
		}
		else // assume that we don't even have a file like that, and that this person has never before played the game.
		{
			engine::logger("unable to find \"settings.dat\", creating one for you! (assuming you are a new player!)");

			std::ofstream create_settings_dat("bin\\settings.dat");

			create_settings_dat << "first_time=true";

			create_settings_dat.close();

			// now let's just make sure we didn't fuck up somewhere in the middle.
			if (create_settings_dat.failbit)
			{
				engine::logger("succesfully created file \"settings.dat\"!");

				engine::logger("starting a new game!");

				new_game();
			}
			else
			{
				engine::logger("unable to create file \"settings.dat\"!");
			}
		}

		first_time.close();
	}

	// fix this shit
	void main_menu(std::string menu_type)
	{
		engine::logger("fetching main menu");
		engine::clear_screen();

		if (menu_type == "new_game")
		{
			std::cout << "+---------------------+" << std::endl;
			std::cout << "+ 1. New Game 2. Exit :" << std::endl;
			std::cout << "+---------------------+" << std::endl;

			std::string userInput = engine::getUserInput();

			if ((userInput == "1") || (userInput == "new game") || (userInput == "new"))
			{
				new_game();
			}
			else if ((userInput == "2") || (userInput == "exit"))
			{
				exit(0);
			}
			else
			{
				std::cout << "You did not enter a valid input! Try again!"; std::cin.get(); main_menu("continue");
			}
		}
		else if (menu_type == "continue")
		{
			std::cout << "+---------------------------------+" << std::endl;
			std::cout << "+ 1. Continue 2. New Game 3. Exit :" << std::endl;
			std::cout << "+---------------------------------+" << std::endl;

			std::string userInput = engine::getUserInput();

			if ((userInput == "Continue") || (userInput == "1") || (userInput == "continue"))
			{
				engine::clear_screen();
				load_save_data();
			}
			else if ((userInput == "new game") || (userInput == "New Game") || (userInput == "new") || (userInput == "2"))
			{
				engine::clear_screen();

				std::cout << "Are you sure you want to start over?" << "\n" << "All your progress will be reset! Y/N < ";

				std::string userInput = engine::getUserInput();

				if ((userInput == "y") || (userInput == "Y"))
				{
					engine::logger("deleting all progress and starting over... :'(");

					engine::clear_screen();

					new_game();
				}
				else if ((userInput == "n") || (userInput == "N"))
				{
					engine::clear_screen();
					main_menu("continue");
				}
				else
				{
					std::cout << "You did not enter a valid input! Try again!"; std::cin.get(); main_menu("continue");
				}
			}
			else
			{
				std::cout << "You did not enter a valid input, try again!"; std::cin.get(); main_menu("continue");
			}
		}
		else
		{
			engine::logger("tried to open the main menu, but did not get a valid version argument!");
		}
	}

	void load_save_data()
	{
		std::string chapter; std::string section; std::string $player_health;

		std::ifstream load("bin\\save.dat");

		while (load >> chapter >> section >> $player_health)
		{
			$player_health = $player_health.erase(0, 7); //remove "health=" from $player_health
			ply::set_health(std::stoi($player_health));
			std::cout << ply::health << std::endl;
		}

		if (load.fail())
		{
			engine::logger(("loading " + chapter + ", " + section + ", player health is " + $player_health + ".")); 
			load_area(chapter, section); 
		}
		else
			engine::logger("failed to load save data.");
	}

	void save(std::string chapter, std::string section)
	{
		std::ofstream save("bin\\save.dat");

		if (save.is_open())
		{
			save << "chapter=" << chapter << std::endl;
			save << "section=" << section << std::endl;
			save << "health=" << ply::health << std::endl;
		}
		else
			engine::logger("failed to open save file.");

		save.close();

		if (save.fail())
			engine::logger("failed to save to file");
		else
			engine::logger(("saved at " + chapter + "  " + section));
	}

	void load_area(std::string chapter, std::string section)
	{
		chapter = chapter.erase(0, 7);
		section = section.erase(0, 7);

		if (chapter == "chapter1")
		{
			if (section == "section1")
			{
				chapter1::section1();
			}
			else if (section == "section2")
			{
				chapter1::section2();
			}
			else if (section == "section3")
			{
				chapter1::section3();
			}
			else
			{
				engine::logger("tried to load chapter1, but didn't get a valid section name!");
			}
		}
		else if (chapter == "chapter2")
		{
			if (section == "section1")
			{
				chapter2::section1();
			}
			else if (section == "section2")
			{
				chapter2::section2();
			}
			else if (section == "section3")
			{
				chapter2::section3();
			}
			else
			{
				engine::logger("tried to load chapter2, but didn't get a valid section name!");
			}
		}
		else if (chapter == "chapter3")
		{
			if (section == "section1")
			{
				chapter3::section1();
			}
			else if (section == "section2")
			{
				chapter3::section2();
			}
			else if (section == "section3")
			{
				chapter3::section3();
			}
			else
			{
				engine::logger("tried to load chapter3, but didn't get a valid section name!");
			}
		}
		else
		{
			engine::logger("tried to load a chapter, but got an invalid chapter name!");
		}
	}

	void new_game()
	{
		{
			engine::logger("changing first_time to false...");

			std::ofstream not_new_game("bin\\settings.dat");

			not_new_game << "first_time=false";

			not_new_game.close();

			if (not_new_game.failbit)
				engine::logger("done!");
			else
				engine::logger("error! could not open \"settings.dat\" for writing!");
			
			ply::set_health(100);
		}

		chapter1::section1();
	}
} //end namespace
