// game.cpp, Freddie Cooke
// define the methods of game class

#include "game.h"

#include "SDL.h"
#include <stdlib.h> // rand
#include <time.h> // time

bool Game::init(const char* title, int x, int y, int w, int h, bool fullscreen) {

	srand(time(NULL));

	SDL_Init(SDL_INIT_VIDEO);

	// decide fullscreen
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	window_ = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
	window_width_ = w, window_height_ = h; // set window properties

	renderer_ = new Renderer(window_);
}

void Game::render() {
	renderer_->update();
}

void Game::update() {
	//
}

void Game::handleEvents() {

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		switch (e.type) {
			case SDL_QUIT:
				running_ = false;
				break;

			default:
				break;
		}
	}
}

void Game::clean() {

	delete renderer_;
	SDL_DestroyWindow(window_);
	delete window_;

	SDL_Quit();
}

int Game::getRandomInt(int floor, int ceil) {
	int value;
	value = rand() % ceil + floor;
	return value;
}
