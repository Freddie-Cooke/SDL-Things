// main.cpp, Freddie Cooke
// SDL as game and main.

#include <iostream>

#include "SDL.h"
#include "Game.h"

using namespace std;

// Define game methods
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	
	// Init SDL, Window, Renderer
	SDL_Init(SDL_INIT_VIDEO);
	g_pWindow_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	g_pRenderer_ = SDL_CreateRenderer(g_pWindow_, -1, 0);

	// Set renderer config
	SDL_SetRenderDrawColor(g_pRenderer_, 0, 0, 0, 255); // Set renderer black

	cout << "Initilised successfully." << endl;
}

void Game::update() {
	//
}

void Game::render() {
	// Refresh renderer black
	SDL_RenderClear(g_pRenderer_);
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

// Main

int main(int argc, char* argv[]) {

	Game* g_pGame = new Game();

	g_pGame->init(
		"Window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600,
		0);

	while (g_pGame->running()) {
		// Do things
		g_pGame->handleEvents();
		g_pGame->update();
		g_pGame->render();
	}

	g_pGame->clean();

	return 0;
}
