// gameobject.h, Freddie Cooke
// describes a general game object

#pragma once

#include <iostream>
#include <string>

#include "loaderparams.h"

using namespace std;

class GameObject {

	public:
		// Draw the object to renderer
		virtual void draw() = 0;
		// Updated the state of the game object
		virtual void update() = 0;
		// Clean up memory
		virtual void clean() = 0;

	protected:
		// Inherited values
		GameObject(const LoaderParams* params) {}
		virtual ~GameObject() {}
};
