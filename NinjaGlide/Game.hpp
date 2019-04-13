#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Input.hpp"
#include "Asset.hpp"

namespace NinjaGlide 
{
	class Game 
	{
	private:
		const float dt = (1.0f / 60.0f);
		sf::RenderWindow window;
		IState *mState;
		//Asset mAsset;
		//Input mInput;
		bool stateChanged;

	public:
		Game(int mWidth, int mHeight, string mTitle);
		sf::Clock mClock;
		void RunGame();
		void StateChanges();
	};
}

