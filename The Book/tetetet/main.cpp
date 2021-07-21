// main.cpp, Freddie Cooke
// SDL as game and main.

#include <iostream>
#include <math.h>

#include "SDL.h"
#include "SDL_image.h"

#include "game.h"
#include "texturemanager.h"

using namespace std;

// Define game methods
bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	// Start game loop
	running_ = true;

	// Init SDL, Window, Renderer
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		cout << "SDL failed to initilise: " << SDL_GetError() << endl;
		return false; // Clean and exit main
	}
	
	// Init SDL_Image
	int IMG_flags = IMG_INIT_PNG;

	if (!(IMG_Init(IMG_flags) && IMG_flags)) {
		cout << "SDL_Image failed to initilise: " << IMG_GetError() << endl;
		return false; // Clean and exit main
	}

	// Set window flags
	int window_flags = 0;
	if (fullscreen) {
		window_flags = SDL_WINDOW_FULLSCREEN;
	}

	// Create window
	window_ = SDL_CreateWindow(title, xpos, ypos, width, height, window_flags);
	if (!window_) { cout << "Failed to create window: " << SDL_GetError(); return false; }

	// Create renderer
	renderer_ = SDL_CreateRenderer(window_, -1, 0);
	if (!renderer_) { cout << "Failed to create renderer: " << SDL_GetError(); return false; }

	// Set renderer config
	SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255); // Set renderer red

	// Load image into texturemanager
	if (!(TextureManager::Instance()->load("assets/animal.png", "ani", renderer_))) {
		cout << "Failed to load image" << endl;
	}

	// Load game objects
	player_.load(0, 0, 96, 64, "ani");
	player2_.load(100, 100, 96, 64, "ani");

	cout << "Initilised successfully." << endl;
	return true;
}

void Game::update() {
	tick_ = SDL_GetTicks();
	player_.update(tick_);
	player2_.update(tick_);
}

void Game::render() {
	// Clear the renderer with solid color
	SDL_RenderClear(renderer_);

	// Render player objects
	player_.draw(renderer_);
	player2_.draw(renderer_);

	// Show the changes
	SDL_RenderPresent(renderer_);
}

void Game::handleEvents() {
	// Event loop
	SDL_Event event; // current event object store
	if(SDL_PollEvent(&event)) { // if there is current event

		switch (event.type) { // do stuff depending on event type

			case SDL_QUIT:
				running_ = false;
				break;

			default:
				break;
		}
	}
}

void Game::clean() {
	
	cout << "Cleaning before exit..." << endl;
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
	player_.clean();
	running_ = false;
	SDL_Quit();
}

// Main
int main(int argc, char* argv[]) {

	Game* g_pGame = new Game();

	if (!(g_pGame->init("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false))) {
		g_pGame->clean();
		cout << "did this";
		return 0;
	}

	while (g_pGame->running()) {
		// Do things
		g_pGame->handleEvents();
		g_pGame->update();
		g_pGame->render();
	}

	g_pGame->clean();

	return 0;
}
