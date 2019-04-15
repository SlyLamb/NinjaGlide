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
	/**
	*	class for managing the projectiles
	*/
	class Projectile
	{
	private:
		std::vector<sf::Sprite> projectiles;	// vector of sprites
		int scoreCounter;						// calculates score based on projectiles moved off screen

	public:
		Projectile() { srand(time(0)); scoreCounter = 0; }	// constructor
		~Projectile(){}										// destructor

		/**
		*	spawns new projetiles off screen to the right
		*/
		void SpawnProjectile(Asset &asset, sf::RenderWindow &mWindow);
		
		/**
		*	moves the projectiles at defined velocity
		*/
		void MoveProjectile(float dt);
		
		/**
		* draws the projectiles
		*/
		void DrawProjectiles(sf::RenderWindow &mWindow);

		/**
		*	returns the sprites for collision detection
		*/
		const std::vector<sf::Sprite> &GetSprites() const;

		/**
		*	increments the score by 1
		*/
		void ScoreUp();
		
		/**
		*	returns the score
		*/
		int GetScore();
	};

}


