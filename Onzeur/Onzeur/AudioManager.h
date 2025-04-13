#pragma once
#include <SFML/Audio.hpp>
#include <iostream>

class AudioManager {
public:
	AudioManager(std::string name, std::string artist, const std::string& filepath);
	void load(const std::string& filepath);
	void update();
	void play();
	void stop();
	void pause();
private:
	sf::Music music;

	sf::Time duration;
	float secondsDuration;

	sf::Time elapsed;
	float secondsElapsed;

	float percentage;
	float tempPercentage;
	int getPercentage();
};