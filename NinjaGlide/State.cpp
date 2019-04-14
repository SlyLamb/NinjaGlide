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

	EPlayer IState::GetPlayer()
	{
		return mPlayer;
	}

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	void Menu::Init() 
	{
		mAsset.LoadTexture("MainMenu", BG_MENU_FILEPATH);
		mAsset.LoadTexture("Title", TITLE_FILEPATH);
		mAsset.LoadTexture("IdleSange", IDLE_SANGE);
		mAsset.LoadTexture("IdleYasha", IDLE_YASHA);

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

	void Menu::Update(float dt, sf::RenderWindow &mWindow) {}

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

		mAsset.LoadTexture("Sange0", SANGE_FRAME_0);
		mAsset.LoadTexture("Sange1", SANGE_FRAME_1);
		mAsset.LoadTexture("Sange2", SANGE_FRAME_2);
		mAsset.LoadTexture("Sange3", SANGE_FRAME_3);
		mAsset.LoadTexture("Sange4", SANGE_FRAME_4);
		mAsset.LoadTexture("Sange5", SANGE_FRAME_5);
		mAsset.LoadTexture("Sange6", SANGE_FRAME_6);
		mAsset.LoadTexture("Sange7", SANGE_FRAME_7);
		mAsset.LoadTexture("Sange8", SANGE_FRAME_8);
		mAsset.LoadTexture("Sange9", SANGE_FRAME_9);

		mAsset.LoadTexture("Yasha0", YASHA_FRAME_0);
		mAsset.LoadTexture("Yasha1", YASHA_FRAME_1);
		mAsset.LoadTexture("Yasha2", YASHA_FRAME_2);
		mAsset.LoadTexture("Yasha3", YASHA_FRAME_3);
		mAsset.LoadTexture("Yasha4", YASHA_FRAME_4);
		mAsset.LoadTexture("Yasha5", YASHA_FRAME_5);
		mAsset.LoadTexture("Yasha6", YASHA_FRAME_6);
		mAsset.LoadTexture("Yasha7", YASHA_FRAME_7);
		mAsset.LoadTexture("Yasha8", YASHA_FRAME_8);
		mAsset.LoadTexture("Yasha9", YASHA_FRAME_9);

		mProjectile = new Projectile();

		if(mPlayer == EPlayer::SANGE)
		{
			player = new Player(mAsset, true);
		}
		else 
		{
			player = new Player(mAsset, false);
		}
		
	}

	void InGame::Update(float dt, sf::RenderWindow &mWindow)
	{
		mProjectile->MoveProjectile(dt);
		if(clock.getElapsedTime().asSeconds() > PROJECTILE_FREQ)
		{
			mProjectile->SpawnProjectile(mAsset, mWindow);
			clock.restart();
		}
		player->Animate(dt);
		player->Update(dt);
	}

	void InGame::Input(sf::RenderWindow &mWindow) 
	{
		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				mWindow.close();
			}
			if (mInput.IsObjectClicked(background, sf::Mouse::Left, mWindow))
			{
				player->Fly();
			}
		}
	}

	void InGame::Draw(float dt, sf::RenderWindow &mWindow) 
	{
		mWindow.clear();
		mWindow.draw(background);
		player->Draw(mWindow);
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

	void Score::Update(float dt, sf::RenderWindow &mWindow) {}

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