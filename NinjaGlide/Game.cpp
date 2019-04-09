#include "Game.hpp"

namespace NinjaGlide 
{
	Game::Game(int mWidth, int mHeight, string mTitle)
	{
		window.create(sf::VideoMode(mWidth, mHeight), mTitle, sf::Style::Close | sf::Style::Titlebar);
		this->mState = new Menu(EState::MENU);
		this->stateChanged = true;
		this->RunGame();
	}

	void Game::StateChanges()
	{
		if (stateChanged == false) 
		{
			return;	// exit function
		}

		EState currentStateEnum = mState->GetState();
		switch (currentStateEnum) 
		{
		case EState::MENU:
			delete mState;
			mState = new Menu(currentStateEnum);
			break;
		case EState::GAME:
			delete mState;
			mState = new InGame(currentStateEnum);
			break;
		case EState::SCORE:
			delete mState;
			mState = new Score(currentStateEnum);
			break;
		}
		stateChanged = false;
	}

	void Game::RunGame() 
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->mClock.getElapsedTime().asSeconds();
		float totalTime = 0.0f;

		while (this->window.isOpen()) 
		{
			StateChanges();

			newTime = mClock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			
			if (frameTime > 0.25f)
			{
				frameTime = 0.25f;
			}

			currentTime = newTime;
			totalTime += frameTime;

			while (totalTime >= dt) 
			{
				mState->Input();
				mState->Update(dt);
				totalTime -= dt;
			}
			interpolation = totalTime / dt;
			mState->Draw(interpolation);
		}
	}
}
