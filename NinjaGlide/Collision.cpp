#include "Collision.hpp"

namespace NinjaGlide
{


	bool Collision::CheckCollision(sf::Sprite spriteA, sf::Sprite spriteB)
	{
		sf::Rect<float> rectA = spriteA.getGlobalBounds();
		sf::Rect<float> rectB = spriteB.getGlobalBounds();

		rectA.height *= 0.8;
		rectA.width *= 0.7;

		rectB.height *= 0.5;
		rectB.width *= 0.5;

		if (rectA.intersects(rectB))
		{
			return true;
		}
		return false;
	}
}