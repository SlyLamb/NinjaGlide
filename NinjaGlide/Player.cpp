#include "Player.hpp"


namespace NinjaGlide
{
	Player::Player(Asset &asset, bool playerChoice)
	{
		It = 0;

		if (playerChoice == true) 
		{
			animationFrames.push_back(asset.GetTexture("Sange0"));
			animationFrames.push_back(asset.GetTexture("Sange1"));
			animationFrames.push_back(asset.GetTexture("Sange2"));
			animationFrames.push_back(asset.GetTexture("Sange3"));
			animationFrames.push_back(asset.GetTexture("Sange4"));
			animationFrames.push_back(asset.GetTexture("Sange5"));
			animationFrames.push_back(asset.GetTexture("Sange6"));
			animationFrames.push_back(asset.GetTexture("Sange7"));
			animationFrames.push_back(asset.GetTexture("Sange8"));
			animationFrames.push_back(asset.GetTexture("Sange9"));
		}
		else 
		{
			animationFrames.push_back(asset.GetTexture("Yasha0"));
			animationFrames.push_back(asset.GetTexture("Yasha1"));
			animationFrames.push_back(asset.GetTexture("Yasha2"));
			animationFrames.push_back(asset.GetTexture("Yasha3"));
			animationFrames.push_back(asset.GetTexture("Yasha4"));
			animationFrames.push_back(asset.GetTexture("Yasha5"));
			animationFrames.push_back(asset.GetTexture("Yasha6"));
			animationFrames.push_back(asset.GetTexture("Yasha7"));
			animationFrames.push_back(asset.GetTexture("Yasha8"));
			animationFrames.push_back(asset.GetTexture("Yasha9"));
		}

		playerSprite.setTexture(animationFrames.at(It));

		playerSprite.setScale(0.25, 0.25);

	}

	void Player::Draw(sf::RenderWindow &mWindow)
	{
		mWindow.draw(playerSprite);
	}

	void Player::Animate(float dt)
	{
		if (mClock.getElapsedTime().asSeconds() > ANIMATION_RATE / animationFrames.size())
		{
			if (It < animationFrames.size() - 1)
			{
				It++;
			}
			else
			{
				It = 0;
			}
			playerSprite.setTexture(animationFrames.at(It));
			mClock.restart();
		}
	}
}
