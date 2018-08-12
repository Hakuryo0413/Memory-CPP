#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>

#define GRAPHICS_PATH "data/graphics/"

class TextureManager
{
public:
  static TextureManager * getInstance();
  static sf::Texture & getTexture(std::string const & filename);

private:
  TextureManager();
  ~TextureManager();

  std::map<std::string, sf::Texture> managerTextures;
  static TextureManager * singletonInstance;
};


