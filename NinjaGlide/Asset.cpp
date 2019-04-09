#include "Asset.hpp"

using namespace std;

namespace NinjaGlide
{
	
	void Asset::LoadTexture(string name, string fName)
	{
		sf::Texture tempTexture;
		if (tempTexture.loadFromFile(fName)) 
		{
			this->mTextures[name] = tempTexture;
		}
	}

	void Asset::LoadFont(string name,  string fName)
	{
		sf::Font tempFont;
		if(tempFont.loadFromFile(fName))
		{
			this->mFonts[name] = tempFont;
		}
	}

	sf::Texture &Asset::GetTexture(string name)
	{
		return this->mTextures.at(name);
	}
	
	sf::Font &Asset::GetFont(string name)
	{
		return this->mFonts.at(name);
	}

}