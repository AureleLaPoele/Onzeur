#include "UIManager.h"

UIManager::UIManager(sf::VideoMode desktopMode)
	: progressBar(sf::Vector2f(0, 25)), progressBarCorner(sf::Vector2f(1500, 25)), progressBarEntire(sf::Vector2f(1500, 25)), progressBarPreview(sf::Vector2f(0, 25)), actualTimeCode(25) {
	progressBar.setPosition(210, 1000);
	progressBar.setFillColor(sf::Color::Green);

	progressBarCorner.setPosition(210, 1000);
	progressBarCorner.setFillColor(sf::Color::Transparent);
	progressBarCorner.setOutlineColor(sf::Color::White);
	progressBarCorner.setOutlineThickness(3.f);

	progressBarEntire.setPosition(210, 1000);
	progressBarEntire.setFillColor(sf::Color(128, 128, 128, 128));

	progressBarPreview.setPosition(210, 1000);
	progressBarPreview.setFillColor(sf::Color(200, 200, 200, 128));
	
	actualTimeCode.setOrigin(actualTimeCode.getRadius(), actualTimeCode.getRadius());
	actualTimeCode.setPosition(210, 1012.5);
}

void UIManager::update(AudioManager& music, float deltaTime) {
	float targetWidth = (music.getPercentage() / 100.f) * totalBarWidth;

	float speed = 300.f;
	if (currentBarWidth < targetWidth)
		currentBarWidth = std::min(currentBarWidth + speed * deltaTime, targetWidth);
	else if (currentBarWidth > targetWidth)
		currentBarWidth = std::max(currentBarWidth - speed * deltaTime, targetWidth);

	progressBar.setSize(sf::Vector2f(currentBarWidth, 25));
	actualTimeCode.setPosition(progressBar.getSize().x+210, 1012.5);
}

void UIManager::updateProgressBarPreviewPos(sf::Vector2i mousePos, sf::RenderWindow& window) {
	if (progressBarEntire.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
		std::cout << "Test\n";
		progressBarPreview.setSize(sf::Vector2f(mousePos.x - 210, 25));
		window.draw(actualTimeCode);
	}
	else {
		progressBarPreview.setSize(sf::Vector2f(0, 25));
	}
	//progressBarPreview.setSize(sf::Vector2f(x, 25));
}

void UIManager::render(sf::RenderWindow& window) {
	window.draw(progressBarEntire);
	window.draw(progressBarPreview);
	window.draw(progressBar);
	window.draw(progressBarCorner);
}