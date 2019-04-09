#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGT 600

int main()
{
	NinjaGlide::Game(WINDOW_WIDTH, WINDOW_HEIGT, "NINJA GLIDE");

	return EXIT_SUCCESS;
}