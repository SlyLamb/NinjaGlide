#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include <stdlib.h>
#include <time.h>
#include "Def.hpp"
#include <vector>


namespace NinjaGlide 
{
	class Projectile
	{
	private:
		std::vector<sf::Sprite> projectiles;
		int scoreCounter;

	public:
		Projectile() { srand(time(0)); scoreCounter = 0; }
		~Projectile(){}

		void SpawnProjectile(Asset &asset, sf::RenderWindow &mWindow);
		void MoveProjectile(float dt);
		void DrawProjectiles(sf::RenderWindow &mWindow);

		const std::vector<sf::Sprite> &GetSprites() const;

		void ScoreUp();
		int GetScore();
	};

}


