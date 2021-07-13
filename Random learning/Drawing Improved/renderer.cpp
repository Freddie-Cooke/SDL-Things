// renderer.cpp, Freddie Cooke
// intilise renderer members

#pragma once

#include "renderer.h"
#include "SDL.h"

Renderer::Renderer(SDL_Window* window) {
	//
	renderer_ = SDL_CreateRenderer(window, -1, 0);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer_);
	delete renderer_;
}

void Renderer::update() {
	
	SDL_RenderPresent(renderer_);
}
