#include "AudioManager.h"

AudioManager::AudioManager(std::string name, std::string artist, const std::string& filepath) {
	load(filepath);
	duration = music.getDuration();
	secondsDuration = duration.asSeconds();
	std::cout << "La musique dure " << secondsDuration << " secondes! \n";
	tempPercentage = -1;
}

void AudioManager::load(const std::string& filepath) {
	if (!music.openFromFile(filepath)) {
		std::cerr << "Erreur de chargement du fichier " << filepath << std::endl;
	}
}

void AudioManager::update() {
	elapsed = music.getPlayingOffset();
	secondsElapsed = elapsed.asSeconds();

	percentage = getPercentage();

	if (tempPercentage != percentage && percentage != 0) {
		std::cout << "Percentage : " << percentage << "%\n";
		tempPercentage = percentage;
	}

}

void AudioManager::play() {
	std::cout << "Play!\n";
	music.play();
}

void AudioManager::stop() {
	std::cout << "Stop!\n";
	music.stop();
}

void AudioManager::pause() {
	std::cout << "Pause!\n";
	music.pause();
}

int AudioManager::getPercentage() {
	percentage = (secondsElapsed * 100) / secondsDuration;
	return percentage;
}