// enemy.h, Freddie Cooke
// header file for GameObject Player

#pragma once
#include "sdlgameobject.h"
#include "loaderparams.h"

class Enemy : public SDLGameObject {

	public:
		Enemy(const LoaderParams* params);

		// Draw the object to renderer
		virtual void draw();
		// Update attributes
		virtual void update();
		// Clean up memory
		virtual void clean();
};
