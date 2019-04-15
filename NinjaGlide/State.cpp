#include "State.hpp"

using namespace std;

namespace NinjaGlide
{
	//----------------------------------------------------------------------
	// IState class  
	//----------------------------------------------------------------------

	/**
	*	returns the state enum
	*/
	EState IState::GetState() 
	{
		return mStateEnum;
	}

	/**
	*	sets the state enum
	*/
	void IState::SetState(EState stateEnum)
	{
		mStateEnum = stateEnum;
	}

	/**
	*	returns true if the state has changed
	*/
	bool IState::hasStateChanged() 
	{
		if(stateChanged)
		{
			stateChanged = false;
			return true;
		}
		return false;
	}

	/**
	*	changes the state
	*/
	void IState::stateChange()
	{
		stateChanged = true;
	}

	/**
	*	returns the player choice enum
	*/
	EPlayer IState::GetPlayer()
	{
		return mPlayer;
	}

	/**
	*	returns the score
	*/
	string IState::GetScore()
	{
		return tempScore;
	}

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	/**
	*	initialize the state
	*/
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

	/**
	*	update the state
	*/
	void Menu::Update(float dt, sf::RenderWindow &mWindow) {}

	/**
	*	process the state inputs
	*/
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
				// switch to InGame state with Sange
				mPlayer = EPlayer::SANGE;
				mStateEnum = EState::GAME;
				stateChanged = true;
			}
			if (mInput.IsObjectClicked(ninjaGirl, sf::Mouse::Left, mWindow))
			{
				// switch to InGame state with Yasha
				mPlayer = EPlayer::YASHA;
				mStateEnum = EState::GAME;
				stateChanged = true;
			}
		}
	}

	/**
	*	draw the state drawables
	*/
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

	/**
	*	initialize the state
	*/
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
			player = new Player(mAsset, true);	// pass true for Sange textures
		}
		else 
		{
			player = new Player(mAsset, false); // pass false for Yasha textures
		}

		// setup score text
		mAsset.LoadFont("Arial", ARIAL_FILEPATH);
		scoreTxt.setFont(mAsset.GetFont("Arial"));
		scoreTxt.setString("0");
		scoreTxt.setCharacterSize(20);
		scoreTxt.setFillColor(sf::Color::White);
		scoreTxt.setPosition(5,5);
	}

	/**
	*	update the state
	*/
	void InGame::Update(float dt, sf::RenderWindow &mWindow)
	{
		// move projectiles
		mProjectile->MoveProjectile(dt);
		if(clock.getElapsedTime().asSeconds() > PROJECTILE_FREQ)
		{
			// spawn more projectiles based on the defined frequency
			mProjectile->SpawnProjectile(mAsset, mWindow);
			clock.restart();
		}
		player->Animate(dt);
		player->Update(dt);

		// check for collisions between player and projectiles
		std::vector<sf::Sprite> projectileSprites = mProjectile->GetSprites();

		for (unsigned int i = 0; i < projectileSprites.size(); ++i )
		{
			// first argument is scaled by 0.8 and second by 0.5
			// always use player first and projectiles second
			if (mCollision.CheckCollision(player->GetSprite(), projectileSprites.at(i)))	
			{
				player->Died();
			}
		}

		if (player->IsDead()) 
		{
			// switch state if player has died
			mStateEnum = EState::SCORE;
			stateChanged = true;
		}
		// setup score for displaying
		mScore = mProjectile->GetScore();
		tempScore = to_string(mScore);
		scoreTxt.setString("SCORE: " + tempScore);
	}

	/**
	*	process the state inputs
	*/
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

	/**
	*	draw the state drawables
	*/
	void InGame::Draw(float dt, sf::RenderWindow &mWindow) 
	{
		mWindow.clear();
		mWindow.draw(background);
		player->Draw(mWindow);
		mProjectile->DrawProjectiles(mWindow);
		mWindow.draw(scoreTxt);
		mWindow.display();
	}

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	/**
	*	initialize the state
	*/
	void Score::Init() 
	{
		mAsset.LoadTexture("Score", BG_SCORE_FILEPATH);
		background.setTexture(mAsset.GetTexture("Score"));

		if (mPlayer == EPlayer::SANGE)
		{
			mAsset.LoadTexture("DeadSange", DEAD_SANGE);
			playerSprite.setTexture(mAsset.GetTexture("DeadSange"));
		}
		else
		{
			mAsset.LoadTexture("DeadYasha", DEAD_YASHA);
			playerSprite.setTexture(mAsset.GetTexture("DeadYasha"));
		}
		playerSprite.setScale(0.4, 0.4);
		playerSprite.setPosition((WINDOW_WIDTH / 2) - (playerSprite.getGlobalBounds().width / 2), WINDOW_HEIGT / 2);

		mAsset.LoadFont("Arial", ARIAL_FILEPATH);
		scoreTxt.setFont(mAsset.GetFont("Arial"));
		scoreTxt.setString("SCORE: " + tempScore);
		scoreTxt.setCharacterSize(20);
		scoreTxt.setFillColor(sf::Color::White);
		scoreTxt.setPosition(5, 5);
	}

	/**
	*	update the state
	*/
	void Score::Update(float dt, sf::RenderWindow &mWindow) {}

	/**
	* process state inputs
	*/
	void Score::Input(sf::RenderWindow &mWindow) 
	{
		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				mWindow.close();
			}
			if (mInput.IsObjectClicked(playerSprite, sf::Mouse::Left, mWindow))
			{
				// switch to Menu state
				mPlayer = EPlayer::NONE;
				mStateEnum = EState::MENU;
				stateChanged = true;
			}
		}
	}

	/**
	*	draw state drawables
	*/
	void Score::Draw(float dt, sf::RenderWindow &mWindow) 
	{
		mWindow.clear();
		mWindow.draw(background);
		mWindow.draw(playerSprite);
		mWindow.draw(scoreTxt);
		mWindow.display();
	}
}