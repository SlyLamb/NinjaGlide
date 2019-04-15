#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

namespace NinjaGlide
{
	/**
		A class used to manage assets such textures and fonts
	*/
	class Asset
	{
	private:
		map<string, sf::Texture> mTextures;		// a key value map of loaded textures
		map<string, sf::Font> mFonts;			// a key value map of loaded fonts

	public:
		Asset() {}		// constructor
		~Asset() {}		// destructor

		/**
		*	saves texture from 'fName' and assigns the key 'name' into map 'mTextures
		*/
		void LoadTexture(string name, string fName);
		
		/**
		*	saves font from 'fName' and assigns the key 'name' into map mFonts
		*/
		void LoadFont(string name, string fName);

		/**
		*	returns texture 'name' from map mTextures
		*/
		sf::Texture &GetTexture(string name);
		
		/**
		*	returns font 'name' from map mFonts
		*/
		sf::Font &GetFont(string name);
	};
}