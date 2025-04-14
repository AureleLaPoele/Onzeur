#include "UIManager.h"

UIManager::UIManager() 
	: progressBar(sf::Vector2f(0, 25)), progressBarCorner(sf::Vector2f(500, 25)) {
	progressBar.setPosition(50, 350);
	progressBar.setFillColor(sf::Color::Green);

	progressBarCorner.setPosition(50, 350);
	progressBarCorner.setFillColor(sf::Color::Transparent);
	progressBarCorner.setOutlineColor(sf::Color::White);
	progressBarCorner.setOutlineThickness(3.f);
}

void UIManager::update(AudioManager& music, float deltaTime) {
	float targetWidth = (music.getPercentage() / 100.f) * totalBarWidth;

	float speed = 300.f;
	if (currentBarWidth < targetWidth)
		currentBarWidth = std::min(currentBarWidth + speed * deltaTime, targetWidth);
	else if (currentBarWidth > targetWidth)
		currentBarWidth = std::max(currentBarWidth - speed * deltaTime, targetWidth);

	progressBar.setSize(sf::Vector2f(currentBarWidth, 25));
}

void UIManager::render(sf::RenderWindow& window) {
	window.draw(progressBar);
	window.draw(progressBarCorner);
}