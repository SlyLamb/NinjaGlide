#include "Projectile.hpp"

namespace NinjaGlide 
{
	/**
	* draws the projectiles
	*/
	void Projectile::DrawProjectiles(sf::RenderWindow &mWindow)
	{
		for (unsigned int i=0; i<projectiles.size(); ++i)
		{
			mWindow.draw(projectiles.at(i));
		}
	}

	/**
	*	spawns new projetiles off screen to the right
	*/
	void Projectile::SpawnProjectile(Asset &asset, sf::RenderWindow &mWindow)
	{
		float randNum = rand() % 550 + 15;	// 550 is the range and 15 is the min : pixels

		sf::Sprite mSprite(asset.GetTexture("Projectile"));
		// randomly position the projectiles off screen -> right
		mSprite.setPosition(mWindow.getSize().x, randNum);
		mSprite.setScale(0.5, 0.5);
	
		projectiles.push_back(mSprite);
	}
	
	/**
	*	moves the projectiles at defined velocity
	*/
	void Projectile::MoveProjectile(float dt)
	{
		for (unsigned int i = 0; i < projectiles.size(); ++i)
		{
			if(projectiles.at(i).getPosition().x < 0 - projectiles.at(i).getGlobalBounds().width)
			{
				// if the projectile is off screen -> left, delete it and increment the score
				projectiles.erase(projectiles.begin() + i);
				ScoreUp();
			}
			else {
				// move projectile towards the left at defined velocity
				float velocity = PROJECTILE_VELOCITY * dt;
				projectiles.at(i).move(-velocity, 0);
			}
		}
	}

	/**
	*	returns the sprites for collision detection
	*/
	const std::vector<sf::Sprite> &Projectile::GetSprites() const 
	{
		return projectiles;
	}

	/**
	*	increments the score by 1
	*/
	void Projectile::ScoreUp()
	{
		++scoreCounter;
	}
	
	/**
	*	returns the score
	*/
	int Projectile::GetScore()
	{
		return scoreCounter;
	}

}
