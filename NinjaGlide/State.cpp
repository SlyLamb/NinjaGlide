#include "State.hpp"
#include "Def.hpp"

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

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	void Menu::Init() 
	{
		mAsset.LoadTexture("MainMenu", BG_MENU_FILEPATH);
		background.setTexture(mAsset.GetTexture("MainMenu"));
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
		}
	}

	void Menu::Draw(float dt, sf::RenderWindow &mWindow)
	{
		mWindow.clear();
		mWindow.draw(background);
		mWindow.display();
	}
	

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	void InGame::Init() {}
	void InGame::Update(float dt) {}
	void InGame::Input(sf::RenderWindow &mWindow) {}
	void InGame::Draw(float dt, sf::RenderWindow &mWindow) {}

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	void Score::Init() {}
	void Score::Update(float dt) {}
	void Score::Input(sf::RenderWindow &mWindow) {}
	void Score::Draw(float dt, sf::RenderWindow &mWindow) {}
}