// main.cpp, Freddie Cooke
// SDL as game and main.

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"
#include "math.h"

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
	SDL_SetRenderDrawColor(renderer_, color_int_, 0, 0, 255); // Set renderer red

	// Load image into memory
	SDL_Surface* temp_surface = IMG_Load("assets/animal.png");

	if(!temp_surface) { // If image fails to load, clean and exit main
		cout << "Failed to load image: " << IMG_GetError(); return false;
	}

	texture_ = SDL_CreateTextureFromSurface(renderer_, temp_surface); // create texture
	SDL_FreeSurface(temp_surface); // Free temporary memory

	// Set rect x, y. set w, h same as source rect
	destRect_.x = sourceRect_.x = 0;
	destRect_.y = sourceRect_.y = 0;
	destRect_.w = sourceRect_.w = 96;
	destRect_.h = sourceRect_.h = 64;

	cout << "Initilised successfully." << endl;
	return true;
}

void Game::update() {
	sourceRect_.x = 96 * int((SDL_GetTicks() / 100)%6);
	destRect_.x = SDL_GetTicks() / 20;
	color_int_ = sin(SDL_GetTicks()*0.001)*255;
}

void Game::render() {
	// Refresh renderer black
	SDL_SetRenderDrawColor(renderer_, color_int_, 0, 0, 255); // Set renderer color
	SDL_RenderClear(renderer_);
	SDL_RenderCopy(renderer_, texture_, &sourceRect_, &destRect_); // render image
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
