// main.cpp, Freddie Cooke
// SDL as game and main.

#include <iostream>

#include "SDL.h"
#include "Game.h"

using namespace std;

// Define game methods
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	// Set random seed
	srand(time(NULL));

	// Init SDL, Window, Renderer
	SDL_Init(SDL_INIT_VIDEO);

	// Set window flags
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	g_pWindow_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	g_pRenderer_ = SDL_CreateRenderer(g_pWindow_, -1, 0);

	cout << "Initilised successfully." << endl;
}

void Game::update() {
	//
}

void Game::render() {

	// Refresh renderer black
	SDL_SetRenderDrawColor(g_pRenderer_, 0, 0, 0, 255);
	SDL_RenderClear(g_pRenderer_);

	// Draw line
	int red[3] = {255, 0, 0};
	int green[3] = {0, 255, 0};
	int blue[3] = {0, 0, 255};

	drawline(getRandomInt(), getRandomInt(), getRandomInt(), getRandomInt(), &red[0]);
	drawline(getRandomInt(), getRandomInt(), getRandomInt(), getRandomInt(), &green[0]);
	drawline(getRandomInt(), getRandomInt(), getRandomInt(), getRandomInt(), &blue[0]);

	// Update the renderer
	SDL_RenderPresent(g_pRenderer_);

}

void Game::handleEvents() {
	// Event loop
	SDL_Event event; // current event object store
	if(SDL_PollEvent(&event)) { // if there is current event

		switch (event.type) { // do stuff depending on event type

			case SDL_QUIT:
				g_bRunning_ = false;
				break;

			default:
				break;
		}
	}
}

void Game::clean() {
	
	cout << "Cleaning before exit..." << endl;
	SDL_DestroyWindow(g_pWindow_);
	SDL_DestroyRenderer(g_pRenderer_);
	SDL_Quit();
}

int Game::getRandomInt() {
	int result = rand() % 600 + 1;
	return result;
}

void Game::drawline(int p1_x, int p1_y, int p2_x, int p2_y, int* color) {
	SDL_SetRenderDrawColor(g_pRenderer_, *color, *(color+1), *(color+2), 255);
	SDL_RenderDrawLine(g_pRenderer_, p1_x, p1_y, p2_x, p2_y);
}

// Main

int main(int argc, char* argv[]) {

	Game* g_pGame = new Game();

	g_pGame->init(
		"Window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		false);

	while (g_pGame->running()) {
		// Do things
		g_pGame->handleEvents();
		g_pGame->update();
		g_pGame->render();
	}

	g_pGame->clean();

	return 0;
}
