#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Def.hpp"
#include <vector>

using namespace std;

int main()
{
	NinjaGlide::Game(WINDOW_WIDTH, WINDOW_HEIGT, "NINJA GLIDE");

	return EXIT_SUCCESS;
}