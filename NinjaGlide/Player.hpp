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
		sf::Sprite playerSprite;
		std::vector<sf::Texture> animationFrames;
		unsigned int It;
		sf::Clock mClock;
		sf::Clock glideClock;
		bool falling;
		bool dead;

	public:
		Player(Asset &asset, bool playerChoice);
		~Player(){}

		void Draw(sf::RenderWindow &mWindow);
		void Animate(float dt);
		void Update(float dt);
		void Fly();
		bool IsFalling();
		bool IsDead();
		void Died();
		const sf::Sprite &GetSprite() const;
	};
}



