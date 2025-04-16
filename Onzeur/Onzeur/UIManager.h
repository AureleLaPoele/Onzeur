#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include "AudioManager.h"

class UIManager {
public:
	UIManager(sf::VideoMode desktopMode);
	void update(AudioManager& music, float deltaTime);
	void render(sf::RenderWindow& window);
	void updateProgressBarPreviewPos(sf::Vector2i mousePos, sf::RenderWindow& window);
private:
	sf::RectangleShape progressBar;
	sf::RectangleShape progressBarCorner;
	sf::RectangleShape progressBarEntire;
	sf::RectangleShape progressBarPreview;
	sf::CircleShape actualTimeCode;
	const float totalBarWidth = 1500.f;
	float currentBarWidth = 0.f;
	const float barHeight = 100.f;
	const float barX = 50.f;
	const float barY = 150.f;
};
