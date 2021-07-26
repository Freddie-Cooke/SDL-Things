// sdlgameobject.h, Freddie Cooke
// game object file with SDL functions

#pragma once

#include "SDL.h"
#include "gameobject.h"
#include "loaderparams.h"
#include "vector2d.h"

#include <string>

using namespace std;

class SDLGameObject : public GameObject {

	public:
		SDLGameObject(const LoaderParams* params);
		virtual void draw();
		virtual void update();
		virtual void clean();

	protected:

		int x_, y_;
		int w_, h_;
		Vector2D position_, velocity_;

		int currentFrame_, currentRow_;

		string textureID_;
};