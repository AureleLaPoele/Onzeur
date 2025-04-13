#include "MusicPlayer.h"

int main() {
	MusicPlayer* app = new MusicPlayer();
	app->run();
	delete app;
	return 0;
}