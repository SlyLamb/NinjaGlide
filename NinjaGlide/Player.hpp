#pragma once

#include <SFML/Graphics.hpp>
#include "Asset.hpp"
#include "Def.hpp"
#include <vector>

namespace NinjaGlide
{
	class Player
	{
	private:
		sf::Sprite playerSprite;					// the sprite for the player
		std::vector<sf::Texture> animationFrames;	// vector of animation textures
		unsigned int It;							// an iterator for the vector
		sf::Clock mClock;							// clock for dt
		sf::Clock glideClock;						// a clock for gliding time
		bool falling;								// boolean to check if falling
		bool dead;									// boolean to check if dead

	public:
		Player(Asset &asset, bool playerChoice);	// constuctor
		~Player(){}									// destructor

		/**
		*	draws the player
		*/
		void Draw(sf::RenderWindow &mWindow);
		
		/**
		* animates the player gliding
		*/
		void Animate(float dt);
		
		/**
		* updates the player states of moving or dying
		*/
		void Update(float dt);
		
		/**
		*	slowly moves the player upwards
		*/
		void Fly();
		
		/**
		*	returns true if the player is falling, otherwise false
		*/
		bool IsFalling();
		
		/**
		* returns true if the player has died
		*/
		bool IsDead();
		
		/**
		*	sets the player 'dead' to true
		*/
		void Died();
		
		/**
		*	returns the player sprite used for collision detection
		*/
		const sf::Sprite &GetSprite() const;
	};
}



