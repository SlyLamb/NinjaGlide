#include "Player.hpp"


namespace NinjaGlide
{
	Player::Player(Asset &asset, bool playerChoice)
	{
		if (playerChoice == true) 
		{
			playerSprite.setTexture(asset.GetTexture("Sange0"));
		}
		else 
		{
			playerSprite.setTexture(asset.GetTexture("Yasha0"));
		}
		playerSprite.setScale(0.25, 0.25);
	}

	void Player::Draw(sf::RenderWindow &mWindow)
	{
		mWindow.draw(playerSprite);
	}
}
