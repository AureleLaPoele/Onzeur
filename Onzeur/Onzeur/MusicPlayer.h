#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AudioManager.h"
#include "UIManager.h"

class MusicPlayer {
public:
	MusicPlayer();
	void run();
	void processEvents();
	void update();
	void render();
	sf::Clock clock;
	float deltaTime;
private:
	const unsigned int WINDOW_WIDTH = 600;
	const unsigned int WINDOW_HEIGHT = 400;

	sf::RenderWindow window;
	bool playing;

	AudioManager music;
	UIManager UI;
	std::vector<AudioManager> musics;
};
