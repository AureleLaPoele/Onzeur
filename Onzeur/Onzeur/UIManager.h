#pragma once
#include <SFML/Graphics.hpp>

class UIManager {
public:
	UIManager();
	void create();
	void render(sf::RenderWindow& window);
};
