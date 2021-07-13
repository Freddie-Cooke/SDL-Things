// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#pragma once

#include "SDL.h"
#include "renderer.h"

enum colors {
	red = {255, 0, 0};
}

class Game {

	public:

		// Initilise SDL Window Renderer
		bool init(const char* title, int x, int y, int w, int h, bool fullscreen);
		// Update the renderer
		void render();
		// Donno
		void update();
		// Event loop
		void handleEvents();
		// Clean pointers
		void clean();

		// Other
		int getRandomInt(int floor, int ceil);

		// Accessors
		bool running() { return running_; }
		Renderer* renderer() { return renderer_; }
		SDL_Window* window() { return window_; }

		// Mutators
		void setRunning( bool value ) { running_ = value; }

	private:
		bool running_ = true; // Main loop condition

		SDL_Window* window_;
		Renderer* renderer_;

		int window_width_; // Window properties
		int window_height_;

		SDL_Rect* rect_;
};
