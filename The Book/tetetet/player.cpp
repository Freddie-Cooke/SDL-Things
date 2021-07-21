// player.cpp, Freddie Cooke
// defining methods of player class

#include "player.h"

void Player::load(int x, int y, int w, int h, string textureID) {
	GameObject::load(x, y, w, h, textureID);
}

void Player::draw(SDL_Renderer* renderer) {
	GameObject::draw(renderer);
}

void Player::update(int ticks) {
	GameObject::update();
	currentFrame_ = int(((ticks / 100)%6));
}

void Player::clean() {
	//
}

