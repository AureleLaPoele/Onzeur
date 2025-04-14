#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() 
    : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Onzeur, le son pop-rock"), music("SubwaySurfer", "none", "assets/songs/SubwaySurfer.ogg") {
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
}

void MusicPlayer::render() {
    window.clear();
    UI.render(window);
    window.display();
}

//for (const auto& elem : vec) {
//    std::cout << elem << std::endl;
//}