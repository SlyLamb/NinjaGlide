#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace NinjaGlide
{
	class Collision
	{
	public:
		Collision(){}

		bool CheckCollision(sf::Sprite spriteA, sf::Sprite spriteB);
	};

}
