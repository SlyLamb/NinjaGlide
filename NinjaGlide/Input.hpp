#pragma once

#include <SFML/Graphics.hpp>

namespace NinjaGlide 
{
	/**
	*	class to help manage input from the mouse
	*/
	class Input
	{
	public:
		Input(){}	// constructor
		~Input(){}	// destructor

		/**
		*	returns true if a sprite was clicked, otherwise false
		*/
		bool IsObjectClicked(sf::Sprite mObject, sf::Mouse::Button mButton, sf::RenderWindow &window);

		/**
		*	returns (x,y) mouse position in relation to the window
		*/
		sf::Vector2i GetMousePos(sf::RenderWindow &window);
	};

}



