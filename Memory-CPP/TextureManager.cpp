#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

TextureManager * TextureManager::singletonInstance;

TextureManager * TextureManager::getInstance()
{
  if (singletonInstance == NULL)
  {
    singletonInstance = new TextureManager();
  }
  return singletonInstance;
}

sf::Texture & TextureManager::getTexture(std::string const & filename)
{
  std::map<std::string, sf::Texture> & textureMap = singletonInstance->managerTextures;

  std::map<std::string, sf::Texture>::iterator pairFound = textureMap.find(filename);
  if (pairFound != textureMap.end())
  {
    return pairFound->second;
  }
  else
  {
    sf::Texture & texture = textureMap[filename];
	  texture.loadFromFile(GRAPHICS_PATH + filename);
    return texture;
  }
}

sf::Font & TextureManager::getTexture(std::string const & filename)
{
  std::map<std::string, sf::Font> & fontMap = singletonInstance->managerFonts;

  std::map<std::string, sf::Font>::iterator pairFound = fontMap.find(filename);
  if (pairFound != fontMap.end())
  {
    return pairFound->second;
  }
  else
  {
    sf::Font & font = fontMap[filename];
	  font.loadFromFile(FONTS_PATH + filename);
    return font;
  }
}

sf::SoundBuffer & TextureManager::getSoundBuffer(std::string const & filename)
{
  std::map<std::string, sf::SoundBuffer> & soundBufferMap = singletonInstance->managerSoundBuffers;

  std::map<std::string, sf::SoundBuffer>::iterator pairFound = soundBufferMap.find(filename);
  if (pairFound != soundBufferMap.end())
  {
    return pairFound->second;
  }
  else
  {
    sf::SoundBuffer & soundBuffer = soundBufferMap[filename];
	  soundBuffer.loadFromFile(AUDIO_PATH + filename);
    return soundBuffer;
  }
}