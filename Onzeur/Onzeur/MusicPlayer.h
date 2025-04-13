#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "AudioManager.h"

class MusicPlayer {
public:
	MusicPlayer();
	void run();
	void processEvents();
	void update();
	void render();
private:
	const unsigned int WINDOW_WIDTH = 600;
	const unsigned int WINDOW_HEIGHT = 400;

	sf::RenderWindow window;
	bool playing;

	AudioManager music;
};
