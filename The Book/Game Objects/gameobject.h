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
		virtual void load(int x, int y, int w, int h, string textureID);
		// Draw the object to renderer
		virtual void draw(SDL_Renderer* renderer);
		// Updated the state of the game object
		virtual void update(int ticks);
		// Clean up memory
		virtual void clean();

	protected:
		// Inherited values
		int x_, y_;
		int w_, h_;
		string textureID_;
		int currentRow_, currentFrame_;
};
