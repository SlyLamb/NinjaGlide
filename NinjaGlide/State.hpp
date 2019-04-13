#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include "Input.hpp"

namespace NinjaGlide
{
	//----------------------------------------------------------------------
	// IState class  
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

	class IState
	{
	protected:
		EState mStateEnum;
		EPlayer mPlayer;
		Asset mAsset;
		Input mInput;
		bool stateChanged;
	public:
		IState() {}
		virtual ~IState() {}

		virtual void Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Input(sf::RenderWindow &mWindow) = 0;
		virtual void Draw(float dt, sf::RenderWindow &mWindow) = 0;

		EState GetState();
		void SetState(EState stateEnum);
		bool hasStateChanged();
		void stateChange();
	};

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	class Menu : public IState
	{
	private:
		sf::Sprite background;
		sf::Sprite title;
		sf::Sprite ninjaBoy;
		sf::Sprite ninjaGirl;

	public:
		Menu(EState stateEnum) { mStateEnum = stateEnum; mPlayer = EPlayer::NONE, Init(); }
		~Menu() {}

		void Init();
		void Update(float dt);
		void Input(sf::RenderWindow &mWindow);
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	class InGame : public IState
	{
	private:
		sf::Sprite background;
		sf::Sprite player;
		sf::Sprite projectile[10];
	public:
		InGame(EState stateEnum) { mStateEnum = stateEnum; Init(); }
		~InGame() {}

		void Init();
		void Update(float dt);
		void Input(sf::RenderWindow &mWindow);
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	class Score : public IState
	{
	private:
		sf::Sprite background;
	public:
		Score(EState stateEnum) { mStateEnum = stateEnum; Init();}
		~Score() {}

		void Init();
		void Update(float dt);
		void Input(sf::RenderWindow &mWindow);
		void Draw(float dt, sf::RenderWindow &mWindow);
	};

}