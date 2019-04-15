#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include "Input.hpp"
#include "Projectile.hpp"
#include "Def.hpp"
#include "Player.hpp"
#include "Collision.hpp"

namespace NinjaGlide
{
	//----------------------------------------------------------------------
	// Enumerator classes for game state and player choice  
	//----------------------------------------------------------------------

	enum EState
	{
		MENU = 0,
		GAME = 1,
		SCORE = 2
	};

	enum EPlayer
	{
		SANGE = 0,
		YASHA = 1,
		NONE = 2
	};

	//----------------------------------------------------------------------
	// IState class  
	//----------------------------------------------------------------------

	class IState
	{
	protected:
		EState mStateEnum;	// the game state
		Asset mAsset;		// the asset manager
		Input mInput;		// the input manager
		bool stateChanged;	// boolean for state changes
		EPlayer mPlayer;	// the player choice
		string tempScore;	// the score string
		sf::Text scoreTxt;	// the score text drawable
		sf::Sprite background; // the background sprite

	public:
		IState() {}				// constructor
		virtual ~IState() {}	// destructor

		/**
		*	initialize the state
		*/
		virtual void Init() = 0;
		
		/**
		*	update the state
		*/
		virtual void Update(float dt, sf::RenderWindow &mWindow) = 0;
		
		/**
		*	process state input
		*/
		virtual void Input(sf::RenderWindow &mWindow) = 0;
		
		/**
		*	draw state drawables
		*/
		virtual void Draw(float dt, sf::RenderWindow &mWindow) = 0;

		/**
		*	returns the state enum
		*/
		EState GetState();
		
		/**
		*	sets the state enum
		*/
		void SetState(EState stateEnum);
		
		/**
		*	returns true if the state has changed
		*/
		bool hasStateChanged();
		
		/**
		*	changes the state
		*/
		void stateChange();
		
		/**
		*	returns the player choice enum
		*/
		EPlayer GetPlayer();
		
		/**
		*	returns the score
		*/
		string GetScore();
	};

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	class Menu : public IState
	{
	private:
		sf::Sprite title;		// the title sprite
		sf::Sprite ninjaBoy;	// Sange character sprite
		sf::Sprite ninjaGirl;	// Yasha character sprite

	public:
		Menu(EState stateEnum) { mStateEnum = stateEnum; Menu::Init(); }	// constructor
		~Menu() {}															// destructor

		/**
		*	initialize the state
		*/
		void Init();

		/**
		*	update the state
		*/
		void Update(float dt, sf::RenderWindow &mWindow);

		/**
		*	process the state inputs
		*/
		void Input(sf::RenderWindow &mWindow);

		/**
		*	draw the state drawables
		*/
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	class InGame : public IState
	{
	private:
		Player *player;				// pointer of type player
		Projectile *mProjectile;	// pointer of type projectiles
		sf::Clock clock;			// clock for projectile spawn times
		Collision mCollision;		// collision detector
		int mScore;					// holds score
		

	public:
		InGame(EState stateEnum, EPlayer playerChoice) { mStateEnum = stateEnum; mPlayer = playerChoice; mScore = 0; InGame::Init(); }	//	constructor
		~InGame() { delete mProjectile; delete player; }					// destructor

		/**
		*	initialize the state
		*/
		void Init();

		/**
		*	update the state
		*/
		void Update(float dt, sf::RenderWindow &mWindow);
		
		/**
		*	process the state inputs
		*/
		void Input(sf::RenderWindow &mWindow);

		/**
		*	draw the state drawables
		*/
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	class Score : public IState
	{
	private:
		sf::Sprite playerSprite;	// the dead player sprite
		
	public:
		Score(EState stateEnum, string score, EPlayer playerChoice) { mStateEnum = stateEnum; tempScore = score; mPlayer = playerChoice; Score::Init(); } // constructor
		~Score() {}				// destructor

		/**
		*	initialize the state
		*/
		void Init();

		/**
		*	update the state
		*/
		void Update(float dt, sf::RenderWindow &mWindow);

		/**
		* process state inputs
		*/
		void Input(sf::RenderWindow &mWindow);

		/**
		*	draw state drawables
		*/
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

}