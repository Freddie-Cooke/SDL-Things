// sdlgameobject.cpp, Freddie Cooke
// defining sdlgameobject class

#include "sdlgameobject.h"
#include "texturemanager.h"
#include "loaderparams.h"
#include "game.h"

// Set attributes as parent parameters
SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params) {
	x_ = params->x(); y_ = params->y();
	w_ = params->w(); h_ = params->h();
	textureID_ = params->textureID();
	currentFrame_ = 1; currentRow_ = 1;
}

void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(textureID_, x_, y_, w_, h_, currentRow_, currentFrame_);
}

void SDLGameObject::update() {
	//
}

void SDLGameObject::clean() {
	//
} 
