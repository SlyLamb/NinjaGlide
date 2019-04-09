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

	//----------------------------------------------------------------------
	// Main Menu class
	//----------------------------------------------------------------------

	void Menu::Init() {}
	void Menu::Update(float dt) {}
	void Menu::Input() {}
	void Menu::Draw(float dt) {}
	

	//----------------------------------------------------------------------
	// In Game class
	//----------------------------------------------------------------------

	void InGame::Init() {}
	void InGame::Update(float dt) {}
	void InGame::Input() {}
	void InGame::Draw(float dt) {}

	//----------------------------------------------------------------------
	// Game Over and final score class
	//----------------------------------------------------------------------

	void Score::Init() {}
	void Score::Update(float dt) {}
	void Score::Input() {}
	void Score::Draw(float dt) {}
}