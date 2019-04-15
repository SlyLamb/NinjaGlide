#include "Collision.hpp"

namespace NinjaGlide
{

	/**
	*	returns true if 'spriteA' has collided with 'spriteB' otherwise false
	*/
	bool Collision::CheckCollision(sf::Sprite spriteA, sf::Sprite spriteB)
	{
		sf::Rect<float> rectA = spriteA.getGlobalBounds();
		sf::Rect<float> rectB = spriteB.getGlobalBounds();

		// resize scale according to character hitbox discrepancies
		rectA.height *= 0.8;
		rectA.width *= 0.7;

		// resize scale according to projectile hitbox discrepancies
		rectB.height *= 0.5;
		rectB.width *= 0.5;

		if (rectA.intersects(rectB))
		{
			return true;
		}
		return false;
	}
}