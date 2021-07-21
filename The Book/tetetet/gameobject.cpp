// gameobject.cpp, Freddie Cooke 
// defines methods for gameobjets

#include "gameobject.h"
#include "texturemanager.h"

void GameObject::load(int x, int y, int w, int h, string textureID) {
	x_ = x; y_ = y;
	w_ = w; h_ = h;

	textureID_ = textureID;
	currentRow_ = 1; currentFrame_ = 1;
}

void GameObject::draw(SDL_Renderer* renderer) {
	TextureManager::Instance()->drawFrame(textureID_, x_, y_, w_, h_, currentRow_, currentFrame_, renderer);
}

void GameObject::update() {
	//
}

void GameObject::clean() {
	//
}