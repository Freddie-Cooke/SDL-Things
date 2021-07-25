// Enemy.cpp, Freddie Cooke
// defining methods of Enemy class

#include "Enemy.h"

Enemy::Enemy(const LoaderParams* params) : SDLGameObject(params) {
	//
}

void Enemy::draw() {
	SDLGameObject::draw();
}

void Enemy::update() {
	x_++;
	currentFrame_ = int(((SDL_GetTicks() / 100) % 6));
}

void Enemy::clean() {
	//
}
