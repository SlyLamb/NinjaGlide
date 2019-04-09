#include <iostream>
#include <SFML/Graphics.hpp>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGTH 800


int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), "NinjaGlide");

	while (window.isOpen())
	{
		// events

		// update

		// draw
		window.clear();

		window.display();




	}

	return EXIT_SUCCESS;

}