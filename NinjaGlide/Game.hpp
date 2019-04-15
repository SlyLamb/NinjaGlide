#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"

namespace NinjaGlide 
{
	/**
	*	a class to manage the main game loop
	*/
	class Game 
	{
	private:
		const float dt = (1.0f / 60.0f);	// frame rate
		sf::RenderWindow window;			// the window for all drawables
		IState *mState;						// a pointer of type Abstract class IState 

	public:
		Game(int mWidth, int mHeight, string mTitle);	// constructor
		~Game();
		sf::Clock mClock;								// clock to help dt
		void RunGame();									// runs the game loop
		void StateChanges();							// checks and processes and state changes
	};
}

