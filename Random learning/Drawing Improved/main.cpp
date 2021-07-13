// main.cpp, Freddie Cooke
// SDL as game and main.

#include <iostream>

#include "SDL.h"
#include "game.h"

using namespace std;

// Main
int main(int argc, char* argv[]) {

	Game* game = new Game();

	game->init("Window", 0, 0, 800, 600, false);

	// Main loop
	while (game->running()) {

		// Do things
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
