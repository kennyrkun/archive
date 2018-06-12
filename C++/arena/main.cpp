#include <iostream>
#include <string>
#include <ctime>    // for the randomNumberGenerator
#include <fstream>  // for the logger

long long enemies_defeated, enemyID;
short game_difficulty;
std::string game_difficulty_t;

void log(std::string log_output)
{
	std::ofstream log("arena.log", std::ios::app);

	if (log.is_open())
	{
		log << log_output << std::endl;

		log.close();

		if (!log.fail())
			log.close();
		else
			std::cerr << "failed to save log";
	}
	else
		std::cerr << "failed to open log stream";
}

int randomNumberGenerator(int maxnumber)
{
	srand((unsigned int)time(NULL)); // I don't like using system time as a seed, becuase when we do lots of randoms at the same time they're all the same. But I don't know of simple alternatives right now.
	unsigned int randomNumber = rand() % maxnumber + 1;

	std::string randomNumber_t = std::to_string(randomNumber);
	log(("generating random number... " + randomNumber_t + "."));

	return randomNumber;
}

class BaseEntity
{
public:
	bool dead;
	bool missed;
	short health;
	short weapon_damage;

	void damage()
	{
		short original_health = health;

		if (game_difficulty == 1)
			health = health - weapon_damage_amount();
		if (game_difficulty == 2)
			health = health - weapon_damage_amount();
		if (game_difficulty == 3)
			health = health - weapon_damage_amount();

		if (health <= 0)
		{
			dead = true;
			return;
		}

		if (health == original_health)
		{
			missed = true;

//			std::cout << "\n" << "entity missed! entity2 has " << health << " health." << std::endl;
//			logger("entity missed" "\n");
		}
		else
		{
			short health_lost = original_health - health;
			std::cout << "\n" << health_lost << " damage was done to entity leaving it with " << health << "." << std::endl;
			log((std::to_string(health_lost) + " was done to entity leaving it with " + std::to_string(health) + "."));
		}
	}

private:
	short weapon_damage_amount()
	{
		static short last_damage;

		if (game_difficulty == 1)
			weapon_damage = randomNumberGenerator(15) + 10;
		if (game_difficulty == 2)
			weapon_damage = randomNumberGenerator(25);
		if (game_difficulty == 3)
			weapon_damage = randomNumberGenerator(40);

		if (weapon_damage == last_damage)
			weapon_damage = +5;

		return weapon_damage;
	}
};

class Player : public BaseEntity
{
public:
	short weapon_damage;

private:
	short weapon_damage_amount() {};
};

class Enemy : public BaseEntity
{
public:
	short weapon_damage;
	std::string type;

	void get()
	{
		log("\n" "generating an enemy...");

		if (game_difficulty == 1)
		{
			health = randomNumberGenerator(100);

			if (health < 50)
				health = 50;
		}

		if (game_difficulty == 2)
		{
			health = randomNumberGenerator(150);

			if (health < 100)
				health = 100;
		}

		if (game_difficulty == 3)
		{
			health = 200;
		}

		log(("enemy health is " +  std::to_string(health)));

		int enemyID = randomNumberGenerator(3);

		if (enemyID == 1)
			type = "Knight1";
		if (enemyID == 2)
			type = "Knight2";
		if (enemyID == 3)
			type = "Knight3";
		if (enemyID == 4)
			type = "Knight4";

		log(("enemy type is " + type));

		log("finished generating enemy." "\n");
	}

private:
	short weapon_damage_amount() {};
};

Player ply;
Enemy enemy;

void combat()
{
	{
		ply.health = 100;
		ply.dead = false;
		enemy.dead = false;
		enemy.get();
		std::cout << "\n" << "You are up against a " << enemy.type << " that has " << enemy.health << " health, on " << game_difficulty_t << " difficulty." << std::endl;
	}

	while (!enemy.dead)
	{
		std::cout << "\n" << "what do you do? < ";

		std::string userInput;
		getline(std::cin, userInput);

		while (userInput != "attack")
		{
			std::cout << "\n" << "do what? < ";
			getline(std::cin, userInput);
		}

		enemy.damage();

		if (enemy.dead)
		{
			std::cout << "\n" << "you killed it." << std::endl;
			log("enemy was killed");
			enemies_defeated++;
			return;
		}
		else
		{
			if (enemy.missed)
			{
				std::cout << "\n" << "enemy missed! you have " << ply.health << " health." << std::endl;
				log("enemy missed" "\n");
			}
		}

		ply.damage();

		if (ply.dead)
		{
			std::cout << "\n" << "you died. pitiful." << std::endl;
			log("player was killed");
			return;
		}
		else
		{
			if (ply.missed)
			{
				std::cout << "\n" << "you missed! enemy has " << enemy.health << " health." << std::endl;
				log("player missed" "\n");
			}
		}
	}
}

void play_again()
{
	std::cout << "\nplay again? < ";
	std::string userInput;
	getline(std::cin, userInput);

	while ((userInput != "y") || (userInput != "Y") || (userInput != "n") || (userInput != "N"))
	{
		if ((userInput) == "y" || (userInput == "Y"))
		{
			int main(); main();
		}
		else if ((userInput == "n") || (userInput == "N"))
		{
			exit(0);
		}
		else
		{
			std::cout << "\n" << "play again? < ";
			getline(std::cin, userInput);
		}
	}
}

int main()
{
	log("new game session started");

	bool diff_not_set(true);
	do
	{	
		std::cout << "select a difficulty < ";
		std::string diff;
		getline(std::cin, diff);
		
		if (diff == "easy") 
		{ 
			game_difficulty = 1;
			game_difficulty_t = "easy";
			break;
		}
		else if (diff == "normal") 
		{ 
			game_difficulty = 2; 
			game_difficulty_t = "normal";
			break;
		}
		else if (diff == "hard")
		{ 
			game_difficulty = 3;
			game_difficulty_t = "hard";
			break;
		}
	} while (diff_not_set);

	combat();

	play_again();

	log("game session ended.");

	return 0;
}
