// gameobject.h, Freddie Cooke
// describes a general game object

#pragma once

#include <iostream>
#include <string>

#include "SDL.h"

using namespace std;

class GameObject {

	public:
		// Create a new object
		void load(int x, int y, int w, int h, string textureID);
		// Draw the object to renderer
		void draw(SDL_Renderer* renderer);
		// Updated the state of the game object
		void update();
		// Clean up memory
		void clean();

	protected:
		// Inherited values
		int x_, y_;
		int w_, h_;
		string textureID_;
		int currentRow_, currentFrame_;
};

