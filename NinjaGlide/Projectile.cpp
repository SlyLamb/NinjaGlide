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
}
