#include "MusicPlayer.h"
#include "Settings.h"

MusicPlayer::MusicPlayer() :
	gameMusic()
{
	gameMusic.openFromFile(AUDIO_PATH "MemoryMusic.ogg");
	gameMusic.setLoop(true);
}

MusicPlayer::~MusicPlayer()
{
}

void MusicPlayer::playMusic()
{
	gameMusic.play();
}