#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace NinjaGlide
{
	/**
	*	class to help determine if a collision has occured
	*/
	class Collision
	{
	public:
		Collision(){}	// constructor
		~Collision(){}	// destructor

		/**
		*	returns true if 'spriteA' has collided with 'spriteB' otherwise false
		*/
		bool CheckCollision(sf::Sprite spriteA, sf::Sprite spriteB);
	};

}
