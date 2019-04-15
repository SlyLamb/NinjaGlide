#include "Input.hpp"

namespace NinjaGlide
{
	/**
	*	returns true if a sprite was clicked, otherwise false
	*/
	bool Input::IsObjectClicked(sf::Sprite mObject, sf::Mouse::Button mButton, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(mButton)) 
		{
			sf::IntRect mRectangle(mObject.getPosition().x, mObject.getPosition().y, mObject.getGlobalBounds().width, mObject.getGlobalBounds().height);
			
			if(mRectangle.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		return false;
	}

	/**
	*	returns (x,y) mouse position in relation to the window
	*/
	sf::Vector2i Input::GetMousePos(sf::RenderWindow &window) 
	{
		return sf::Mouse::getPosition(window);
	}

}