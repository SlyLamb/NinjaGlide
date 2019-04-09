#pragma once

#include <SFML/Graphics.hpp>

namespace NinjaGlide 
{
	class Input
	{
	public:
		Input(){}
		~Input(){}

		bool IsObjectClicked(sf::Sprite mObject, sf::Mouse::Button mButton, sf::RenderWindow &window);

		sf::Vector2i GetMousePos(sf::RenderWindow &window);
	};

}



