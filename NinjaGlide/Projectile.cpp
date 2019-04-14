#include "Projectile.hpp"

namespace NinjaGlide 
{
	void Projectile::DrawProjectiles(sf::RenderWindow &mWindow)
	{
		for (unsigned int i=0; i<projectiles.size(); ++i)
		{
			mWindow.draw(projectiles.at(i));
		}
	}

	void Projectile::SpawnProjectile(Asset &asset, sf::RenderWindow &mWindow)
	{
		float randNum = rand() % 550 + 15;

		sf::Sprite mSprite(asset.GetTexture("Projectile"));
		mSprite.setPosition(mWindow.getSize().x, randNum);
		mSprite.setScale(0.9, 0.9);
	
		projectiles.push_back(mSprite);
	}
	
	void Projectile::MoveProjectile(float dt)
	{
		for (unsigned int i = 0; i < projectiles.size(); ++i)
		{
			if(projectiles.at(i).getPosition().x < 0 - projectiles.at(i).getGlobalBounds().width)
			{
				projectiles.erase(projectiles.begin() + i);
			}
			else {
				float velocity = PROJECTILE_VELOCITY * dt;
				projectiles.at(i).move(-velocity, 0);
			}
		}
	}

}
