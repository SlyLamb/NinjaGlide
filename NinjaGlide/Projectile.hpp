#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include <random>
#include "Def.hpp"


namespace NinjaGlide 
{
	class Projectile
	{
	private:
		std::vector<sf::Sprite> projectiles;

	public:
		Projectile(){ srand(time(0)); }
		~Projectile(){}

		void SpawnProjectile(Asset &asset, sf::RenderWindow &mWindow);
		void MoveProjectile(float dt);
		void DrawProjectiles(sf::RenderWindow &mWindow);
	};

}


