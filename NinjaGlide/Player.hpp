#pragma once

#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include "Def.hpp"

namespace NinjaGlide
{
	class Player
	{
	private:
		sf::Sprite playerSprite;

	public:
		Player(Asset &asset, bool playerChoice);
		~Player(){}

		void Draw(sf::RenderWindow &mWindow);
	};
}



