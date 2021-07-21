// enemy.h, Freddie Cooke
// header file for GameObject Player

#pragma once
#include "gameobject.h"

class Enemy : public GameObject {

	public:
		// Create a new object
		void load(int x, int y, int w, int h, string textureID);
		// Draw the object to renderer
		void draw(SDL_Renderer* renderer);
		// Updated the state of the game object
		void update(int ticks);
		// Clean up memory
		void clean();
};
