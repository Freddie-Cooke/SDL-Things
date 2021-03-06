// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#pragma once

#include <vector>

#include "SDL.h"
#include "texturemanager.h"
#include "player.h"
#include "enemy.h"
#include "gameobject.h"

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

		// Game objects
		std::vector<GameObject*> gameObjects_;
		GameObject* player_;
		GameObject* enemy_;

		int ticks_;
};
