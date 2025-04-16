#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(sf::VideoMode desktopMode)
    : window(desktopMode , "Onzeur, le son pop-rock", sf::Style::Fullscreen), music("SubwaySurfer", "none", "assets/songs/SubwaySurfer.ogg"), UI(desktopMode) {
    playing = false;
    window.setVerticalSyncEnabled(true);
}

void MusicPlayer::run() {
	while (window.isOpen()) {
        deltaTime = clock.restart().asSeconds();
        processEvents();
        update();
        render();
	}
}

void MusicPlayer::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.key.code == sf::Keyboard::Space) {
                if (!playing) {
                    music.play();
                    playing = true;
                }
                else {
                    music.pause();
                    playing = false;
                }
            }
        }
    }
}

void MusicPlayer::update() {
    music.update();
    UI.update(music, deltaTime);
    //UI.updateProgressBarPreviewPos(sf::Mouse::getPosition(), window);
}

void MusicPlayer::render() {
    window.clear();
    UI.render(window);
    UI.updateProgressBarPreviewPos(sf::Mouse::getPosition(), window);
    window.display();
}

//for (const auto& elem : vec) {
//    std::cout << elem << std::endl;
//}