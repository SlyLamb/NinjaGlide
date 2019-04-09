#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

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

	class IState
	{
	protected:
		EState mStateEnum;
	public:
		IState() {}
		virtual ~IState() {}

		virtual void Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Input() = 0;
		virtual void Draw(float dt) = 0;

		EState GetState();
		void SetState(EState stateEnum);
	};

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	class Menu : public IState
	{
	public:
		Menu(EState stateEnum) { mStateEnum = stateEnum; }
		~Menu() {}

		void Init();
		void Update(float dt);
		void Input();
		void Draw(float dt);
	};

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	class InGame : public IState
	{
	public:
		InGame(EState stateEnum) { mStateEnum = stateEnum; }
		~InGame() {}

		void Init();
		void Update(float dt);
		void Input();
		void Draw(float dt);
	};

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	class Score : public IState
	{
	public:
		Score(EState stateEnum) { mStateEnum = stateEnum; }
		~Score() {}

		void Init();
		void Update(float dt);
		void Input();
		void Draw(float dt);
	};

}