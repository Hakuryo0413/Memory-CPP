#pragma once
#include <map>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#define GRAPHICS_PATH "data/graphics/"
#define FONTS_PATH "data/fonts/"
#define AUDIO_PATH "data/audio/"

class TextureManager
{
public:
  static TextureManager * getInstance();
  static sf::Texture & getTexture(std::string const & filename);
  static sf::Font & getFont(std::string const & filename);
  static sf::SoundBuffer & getSoundBuffer(std::string const & filename);

private:
  TextureManager();
  ~TextureManager();

  std::map<std::string, sf::Texture> managerTextures;
  std::map<std::string, sf::Font> managerFonts;
  std::map<std::string, sf::SoundBuffer> managerSoundBuffers;
  static TextureManager * singletonInstance;
};


