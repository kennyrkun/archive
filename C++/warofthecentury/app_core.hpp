#pragma once

#pragma region HEADERS

// I/O Operations
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

// TIME
#include <time.h>

// MISC
#include <tchar.h>  
#include <conio.h> // for kbhit
#pragma endregion

#pragma region VARIABLES
// FORWARD DECLARE GLOBAL FUNCTIONS HERE
int main();

// areas of the game
namespace chapter1
{
	void section1();
	void section2();
	void section3();
}

namespace chapter2
{
	void section1();
	void section2();
	void section3();
}

namespace chapter3
{
	void section1();
	void section2();
	void section3();
}
#pragma endregion

namespace game
{
	namespace engine
    {
        std::string getUserInput();

        template<typename T>
        std::string to_string(const T& value);

		int randomNumberGenerator(int percentNumber);

        void wait_for(int mseconds);

        void clear_screen();

        void pause();

        void logger(std::string output);

        void errorReporter(std::string errorType, std::string location);

		void prepare_engine();
    }

	namespace ply
    {
		extern short health;
		extern bool dead;
		extern std::string name;

//		void isDead(bool isdead);

		void damage(int amount);

		void heal(int amount);

		void set_health(int amount);
    }

	void pre_game_setup();

	void main_menu(std::string menu_type);

	void load_save_data();

	void save(std::string chapter, std::string section);

	void load_area(std::string chapter, std::string section);

	void new_game();
} //end namespace
