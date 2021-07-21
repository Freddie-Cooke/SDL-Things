// Enemy.cpp, Freddie Cooke
// defining methods of Enemy class

#include "Enemy.h"

void Enemy::load(int x, int y, int w, int h, string textureID) {
	GameObject::load(x, y, w, h, textureID);
}

void Enemy::draw(SDL_Renderer* renderer) {
	GameObject::draw(renderer);
}

void Enemy::update(int ticks) {
	GameObject::update(ticks);
	currentFrame_ = int(((ticks / 100)%6));
}

void Enemy::clean() {
	//
}

