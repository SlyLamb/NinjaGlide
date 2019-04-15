#include "Game.hpp"

namespace NinjaGlide 
{
	/** 
	*	constructor
	*/
	Game::Game(int mWidth, int mHeight, string mTitle)
	{
		// create the game window
		window.create(sf::VideoMode(mWidth, mHeight), mTitle, sf::Style::Close | sf::Style::Titlebar);
		//create the initial Menu state
		this->mState = new Menu(EState::MENU);
		this->mState->stateChange();
		// run game loop
		this->RunGame();
	}

	/**
	*	destructor
	*/
	Game::~Game() { delete mState; }

	/**
	*	checks and processes state changes
	*/
	void Game::StateChanges()
	{
		if (!mState->hasStateChanged()) 
		{
			return;	// exit function if no state changes
		}
		// init temp variables
		EPlayer tempPlayer = EPlayer::NONE;
		string mScore = "";
		// save new state as current state
		EState currentStateEnum = mState->GetState();
		switch (currentStateEnum) 
		{
		case EState::MENU:
			// switch game to Menu state
			delete mState;
			mState = new Menu(currentStateEnum);
			break;
		case EState::GAME:
			// save the player chosen from Menu
			tempPlayer = mState->GetPlayer();
			// switch game to Game state
			delete mState;
			mState = new InGame(currentStateEnum, tempPlayer);
			break;
		case EState::SCORE:
			// save player chosen and score
			tempPlayer = mState->GetPlayer();
			mScore = mState->GetScore();
			// switch game to Score state
			delete mState;
			mState = new Score(currentStateEnum, mScore, tempPlayer);
			break;
		}
	}

	/**
	*	runs the game loop
	*/
	void Game::RunGame() 
	{
		float newTime, frameTime, interpolation;
		float currentTime = this->mClock.getElapsedTime().asSeconds();
		float totalTime = 0.0f;

		while (this->window.isOpen()) 
		{
			// check if any state changes
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
				// process inputs from current game state
				mState->Input(window);
				// process updates from current game state
				mState->Update(dt, window);
				totalTime -= dt;
			}
			interpolation = totalTime / dt;
			// draw all drawables from current game state
			mState->Draw(interpolation, window);
		}
	}
}
