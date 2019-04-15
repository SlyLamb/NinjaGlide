#include "Asset.hpp"

using namespace std;

namespace NinjaGlide
{
	/**
	*	saves texture from 'fName' and assigns the key 'name' into map 'mTextures
	*/
	void Asset::LoadTexture(string name, string fName)
	{
		sf::Texture tempTexture;
		if (tempTexture.loadFromFile(fName)) 
		{
			this->mTextures[name] = tempTexture;
		}
	}

	/**
	*	saves font from 'fName' and assigns the key 'name' into map mFonts
	*/
	void Asset::LoadFont(string name,  string fName)
	{
		sf::Font tempFont;
		if(tempFont.loadFromFile(fName))
		{
			this->mFonts[name] = tempFont;
		}
	}

	/**
	*	returns texture 'name' from map mTextures
	*/
	sf::Texture &Asset::GetTexture(string name)
	{
		return this->mTextures.at(name);
	}
	
	/**
	*	returns font 'name' from map mFonts
	*/
	sf::Font &Asset::GetFont(string name)
	{
		return this->mFonts.at(name);
	}

}