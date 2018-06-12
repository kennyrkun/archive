#include "app_core.hpp"

namespace chapter1
{
	void section1()
	{
		game::engine::logger("now in chapter1, section1.");
		game::save("chapter1", "section1");

		// title chapter1 section1

		std::cout << "You awake greeted with silence."; std::cin.get();
		std::cout << "Sitting in your bed you question what exactly is going on."; std::cin.get();

		std::cout << "You get yourself dressed, and step outside." << std::endl;

		std::cin.get();

		std::cout << "";

		std::cin.get();

		game::load_area("chapter1", "section2");
	}

	void section2()
	{
		game::engine::logger("now in chapter1, section2.");
		game::save("chapter1", "section2");

		std::cout << "chapter1, section2" << std::endl;

		std::cin.get();

		game::load_area("chapter1", "section3");
	}

	void section3()
	{
		game::engine::logger("now in chapter1, section3.");
		game::save("chapter1", "section3");

		std::cout << "chapter1, section3" << std::endl;

		std::cin.get();

		game::load_area("chapter2", "section1");
	}
}

namespace chapter2
{
	void section1()
	{
		game::engine::logger("now in chapter2, section1.");
		game::save("chapter2", "section1");

		std::cout << "chapter2, section1" << std::endl;

		std::cin.get();

		game::load_area("chapter2", "section2");
	}

	void section2()
	{
		game::engine::logger("now in chapter2, section2.");
		game::save("chapter2", "section2");

		std::cout << "chapter2, section2" << std::endl;

		std::cin.get();

		game::load_area("chapter2", "section3");
	}

	void section3()
	{
		game::engine::logger("now in chapter2, section3.");
		game::save("chapter2", "section3");

		std::cout << "chapter2, section3" << std::endl;

		std::cin.get();

		game::load_area("chapter3", "section1");
	}
}

namespace chapter3
{
	void section1()
	{
		game::engine::logger("now in chapter3, section1.");
		game::save("chapter3", "section1");

		std::cout << "chapter3, section1" << std::endl;

		std::cin.get();

		game::load_area("chapter3", "section2");
	}

	void section2()
	{
		game::engine::logger("now in chapter3, section2.");
		game::save("chapter3", "section2");

		std::cout << "chapter3, section2" << std::endl;

		std::cin.get();

		game::load_area("chapter3", "section3");
	}

	void section3()
	{
		game::engine::logger("now in chapter3, section3.");
		game::save("chapter3", "section3");

		std::cout << "chapter3, section3" << std::endl;

		std::cin.get();

		// end game
	}
}

/*
void randomEncounter()
{
	// IN Canada
	int rand_encounterID = game::engine::randomNumberGenerator(2);

	int rand_strength = game::engine::randomNumberGenerator(10);

	if (rand_encounterID == 1)
	{
		std::cout << "You encounter wolf with a strength of " << rand_strength << std::endl;
	}
	else
	{
		game::engine::errorReporter("internal", __func__);
	}
	// IN Canada
}
*/
