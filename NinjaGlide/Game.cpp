#include "Game.hpp"

namespace NinjaGlide 
{
	Game::Game(int mWidth, int mHeight, string mTitle)
	{
		window.create(sf::VideoMode(mWidth, mHeight), mTitle, sf::Style::Close | sf::Style::Titlebar);
		this->mState = new Menu(EState::MENU);
		this->mState->stateChange();
		this->RunGame();
	}

	void Game::StateChanges()
	{
		if (!mState->hasStateChanged()) 
		{
			return;	// exit function
		}
		EPlayer tempPlayer = EPlayer::NONE;
		string mScore = "";
		EState currentStateEnum = mState->GetState();
		switch (currentStateEnum) 
		{
		case EState::MENU:
			delete mState;
			mState = new Menu(currentStateEnum);
			break;
		case EState::GAME:
			tempPlayer = mState->GetPlayer();
			delete mState;
			mState = new InGame(currentStateEnum, tempPlayer);
			break;
		case EState::SCORE:
			tempPlayer = mState->GetPlayer();
			mScore = mState->GetScore();
			delete mState;
			mState = new Score(currentStateEnum, mScore, tempPlayer);
			break;
		}
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
				mState->Input(window);
				mState->Update(dt, window);
				totalTime -= dt;
			}
			interpolation = totalTime / dt;
			mState->Draw(interpolation, window);
		}
	}
}
