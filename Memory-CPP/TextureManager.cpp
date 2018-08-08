#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

TextureManager::TextureManager * TextureManager::singletonInstance;

TextureManager::TextureManager * getTextureManager()
{
  if (singletonInstance == NULL)
  {
    singletonInstance = new TextureManager();
  }
  return singletonInstance;
}

sf::Texture & TextureManager::GetTexture(std::string const & filename)
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
    texture.loadFromFile(filename);
    return texture;
  }
}