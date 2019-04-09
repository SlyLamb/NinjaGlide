#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

namespace NinjaGlide
{
	class Asset
	{
	private:
		map<string, sf::Texture> mTextures;
		map<string, sf::Font> mFonts;

	public:
		Asset() {}
		~Asset() {}

		void LoadTexture(string name, string fName);
		void LoadFont(string name, string fName);

		sf::Texture &GetTexture(string name);
		sf::Font &GetFont(string name);
	};
}