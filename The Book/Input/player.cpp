// player.cpp, Freddie Cooke
// defining methods of player class

#include "player.h"

Player::Player(const LoaderParams* params) : SDLGameObject(params) {
	// Defined in args
}

void Player::draw() {
	SDLGameObject::draw();
}

void Player::update() {
	SDLGameObject::update();
	velocity_.setX(1);
	currentFrame_ = int(((SDL_GetTicks() / 100) % 6));
}

void Player::clean() {
	//
}
