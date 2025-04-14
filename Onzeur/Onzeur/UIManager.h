#pragma once
#include <SFML/Graphics.hpp>
#include "AudioManager.h"

class UIManager {
public:
	UIManager();
	void update(AudioManager& music, float deltaTime);
	void render(sf::RenderWindow& window);
private:
	sf::RectangleShape progressBar;
	sf::RectangleShape progressBarCorner;
	const float totalBarWidth = 500.f;
	float currentBarWidth = 0.f;
	const float barHeight = 100.f;
	const float barX = 50.f;
	const float barY = 150.f;
};
