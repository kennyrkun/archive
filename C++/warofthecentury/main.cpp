#include "app_core.hpp"

int main() // this handles ONLY the startup of the game, and the closing of it.
{
	game::engine::prepare_engine();

	std::cout << game::ply::health;

	game::ply::damage(10);

	std::cout << game::ply::health;

	game::pre_game_setup();

	std::cin.get();

	return 0;
}
