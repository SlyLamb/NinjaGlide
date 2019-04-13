#include "State.hpp"

using namespace std;

namespace NinjaGlide
{
	//----------------------------------------------------------------------
	// IState class  
	//----------------------------------------------------------------------

	EState IState::GetState() 
	{
		return mStateEnum;
	}

	void IState::SetState(EState stateEnum)
	{
		mStateEnum = stateEnum;
	}

	bool IState::hasStateChanged() 
	{
		if(stateChanged)
		{
			stateChanged = false;
			return true;
		}
		return false;
	}

	void IState::stateChange()
	{
		stateChanged = true;
	}

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	void Menu::Init() 
	{
		mAsset.LoadTexture("MainMenu", BG_MENU_FILEPATH);
		mAsset.LoadTexture("Title", TITLE_FILEPATH);
		mAsset.LoadTexture("IdleSange", IDLE_SANGE_FRAME_0);
		mAsset.LoadTexture("IdleYasha", IDLE_YASHA_FRAME_0);

		background.setTexture(mAsset.GetTexture("MainMenu"));
		title.setTexture(mAsset.GetTexture("Title"));
		ninjaBoy.setTexture(mAsset.GetTexture("IdleSange"));
		ninjaGirl.setTexture(mAsset.GetTexture("IdleYasha"));

		title.setPosition((WINDOW_WIDTH / 2) - (title.getGlobalBounds().width / 2), 
			title.getGlobalBounds().height);

		ninjaBoy.setScale(0.5, 0.5);
		ninjaGirl.setScale(0.5, 0.5);
		ninjaBoy.setPosition((WINDOW_WIDTH / 4), (WINDOW_HEIGT / 2 ));
		ninjaGirl.setPosition((WINDOW_WIDTH / 4) * 2.5, (WINDOW_HEIGT / 2) - 30);
	}

	void Menu::Update(float dt) {}

	void Menu::Input(sf::RenderWindow &mWindow)
	{
		sf::Event e;
		while (mWindow.pollEvent(e)) 
		{
			if (e.type == sf::Event::Closed)
			{
				mWindow.close();
			}
			if (mInput.IsObjectClicked(ninjaBoy, sf::Mouse::Left, mWindow))
			{
				mPlayer = EPlayer::SANGE;
				mStateEnum = EState::GAME;
				stateChanged = true;
			}
			if (mInput.IsObjectClicked(ninjaGirl, sf::Mouse::Left, mWindow))
			{
				mPlayer = EPlayer::YASHA;
				mStateEnum = EState::GAME;
				stateChanged = true;
			}
		}
	}

	void Menu::Draw(float dt, sf::RenderWindow &mWindow)
	{
		mWindow.clear();
		mWindow.draw(background);
		mWindow.draw(title);
		mWindow.draw(ninjaBoy);
		mWindow.draw(ninjaGirl);
		mWindow.display();
	}
	

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	void InGame::Init() 
	{
		mAsset.LoadTexture("InGame", BG_GAME_FILEPATH);
		background.setTexture(mAsset.GetTexture("InGame"));

		mAsset.LoadTexture("Projectile", PROJECTILE_FILEPATH);

		mProjectile = new Projectile();
	}

	void InGame::Update(float dt) {}

	void InGame::Input(sf::RenderWindow &mWindow) 
	{
		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				mWindow.close();
			}
			
		}
	}

	void InGame::Draw(float dt, sf::RenderWindow &mWindow) 
	{
		mWindow.clear();
		mWindow.draw(background);
		mProjectile->DrawProjectiles(mWindow);
		mWindow.display();
	}

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	void Score::Init() 
	{
		mAsset.LoadTexture("Score", BG_SCORE_FILEPATH);
		background.setTexture(mAsset.GetTexture("Score"));
	}

	void Score::Update(float dt) {}

	void Score::Input(sf::RenderWindow &mWindow) 
	{
		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				mWindow.close();
			}

		}
	}

	void Score::Draw(float dt, sf::RenderWindow &mWindow) 
	{
		mWindow.clear();
		mWindow.draw(background);
		mWindow.display();
	}
}