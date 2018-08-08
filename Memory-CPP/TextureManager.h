#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>


class TextureManager
{
public:
  static TextureManager * getTextureManager();
  static sf::Texture & GetTexture(std::string const & filename);

private:
  TextureManager();
  ~TextureManager();

  std::map<std::string, sf::Texture> managerTextures;
  static TextureManager * singletonInstance;
};


