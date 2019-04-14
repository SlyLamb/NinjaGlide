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
		std::cout << randNum << endl;

		sf::Sprite mSprite(asset.GetTexture("Projectile"));
		mSprite.setPosition(mWindow.getSize().x, randNum);
	
		projectiles.push_back(mSprite);
	}
	
	void Projectile::MoveProjectile(float dt)
	{
		for (unsigned int i = 0; i < projectiles.size(); ++i)
		{
			sf::Vector2f position = projectiles.at(i).getPosition();
			float velocity = PROJECTILE_VELOCITY * dt;
			projectiles.at(i).move(-velocity, 0);
		}
	}

}
