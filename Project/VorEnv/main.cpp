/// <summary>
/// @mainpage FYP - Voronoi Diagrams and their usage in games development
/// @Authors John O'Grady
/// @Version 1.0
/// </summary>

//	Project
#include "Game.h"

/// <summary>
/// Entry point for the program.
/// </summary>
/// <returns></returns>
int main()
{
	Game* game;
	game = new Game();
	game->run();
	return 0;
}