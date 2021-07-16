// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#pragma once

#include "SDL.h"

class Game {

	public:

		// Initilise SDL Window Renderer
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		// Update the renderer
		void render();
		// Donno
		void update();
		// Event loop
		void handleEvents();
		// Clean pointers
		void clean();

		// Accessors
		bool running() { return running_; }

		// Mutators
		void setRunning( bool value ) { running_ = value; }

	private:
		// Game vars
		bool running_;
		SDL_Window* window_;
		SDL_Renderer* renderer_;

		// Update vars
		int color_int_ = 0;
		int currentFrame_;
};
