// sdlgameobject.cpp, Freddie Cooke
// defining sdlgameobject class

#include <iostream>

#include "sdlgameobject.h"
#include "texturemanager.h"
#include "loaderparams.h"
#include "game.h"

// Set attributes as parent parameters
SDLGameObject::SDLGameObject(const LoaderParams* params) : GameObject(params), position_(params->x(), params->y()), velocity_(0,0) {
	x_ = params->x(); y_ = params->y();
	w_ = params->w(); h_ = params->h();
	textureID_ = params->textureID();
	currentFrame_ = 1; currentRow_ = 1;
}

void SDLGameObject::draw() {
	TextureManager::Instance()->drawFrame(textureID_, position_.x(), position_.y(), w_, h_, currentRow_, currentFrame_);
}

void SDLGameObject::update() {
	position_ += velocity_;
	std::cout << "x: " << position_.x() << std::endl;
}

void SDLGameObject::clean() {
	//
} 
