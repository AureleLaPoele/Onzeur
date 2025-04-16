#include "MusicPlayer.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	MusicPlayer* app = new MusicPlayer(desktopMode);
	app->run();
	delete app;
	return 0;
}