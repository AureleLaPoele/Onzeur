#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "AudioManager.h"
#include "UIManager.h"

class MusicPlayer {
public:
	MusicPlayer(sf::VideoMode desktopMode);
	void run();
	void processEvents();
	void update();
	void render();
	sf::Clock clock;
	float deltaTime;
private:
	const unsigned int WINDOW_WIDTH = 1920;
	const unsigned int WINDOW_HEIGHT = 1080;

	sf::RenderWindow window;
	bool playing;

	AudioManager music;
	UIManager UI;
	std::vector<AudioManager> musics;
};
