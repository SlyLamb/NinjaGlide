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

		playerSprite.setPosition(WINDOW_WIDTH / 6, 10);
		
		falling = true;

		dead = false;
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

	bool Player::IsFalling()
	{
		if (falling) { return true; }
		return false;
	}

	void Player::Update(float dt)
	{
		if (playerSprite.getGlobalBounds().top < 0)
		{
			playerSprite.setPosition(WINDOW_WIDTH / 6, 0);
		}
		if (playerSprite.getGlobalBounds().top > WINDOW_HEIGT - playerSprite.getGlobalBounds().height + 15)
		{
			//playerSprite.setPosition(WINDOW_WIDTH / 6, (WINDOW_HEIGT - playerSprite.getGlobalBounds().height));
			dead = true;
		}

		if (IsFalling()) 
		{
			playerSprite.move(0, GRAVITY * dt);
		}
		else
		{
			playerSprite.move(0, GLIDE_VELOCITY * dt);
		}

		if (glideClock.getElapsedTime().asSeconds() > GLIDE_TIME)
		{
			glideClock.restart();
			falling = true;
		}
	}

	void Player::Fly()
	{
		glideClock.restart();
		falling = false;
	}

	bool Player::IsDead()
	{
		if (dead) { return true; }
		return false;
	}

	void Player::Died() { dead = true; }

	const sf::Sprite &Player::GetSprite() const
	{
		return playerSprite;
	}
}
