#pragma once

#include <vector>
#include <SFML/Graphics.hpp>


namespace NinjaGlide 
{
	class Projectile
	{
		
	public:
		Projectile(){}
		~Projectile(){}

		std::vector<sf::Sprite> projectiles;

		void DrawProjectiles(sf::RenderWindow &mWindow);
	};

}


