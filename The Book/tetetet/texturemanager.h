// texturemanager.cpp, Freddie cooke

#pragma once

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

#include <map>
#include <string>

using namespace std;

class TextureManager {

	public:

		// Singleton
		static TextureManager* Instance() {
			if (instance == 0) { // If no current instance create and return one
				instance = new TextureManager();
				return instance;
			}
			return instance; // Return the current instance
		}

		// Load images and textures
		bool load(string fileName, string id, SDL_Renderer* renderer);

		// Draw a static image using size, position, and identifier
		void draw(string id, int x, int y, int w, int h, SDL_Renderer* renderer_, SDL_RendererFlip flip = SDL_FLIP_NONE);

		// Draw animated image
		void drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	private:
		TextureManager() {} // Only accessible through the current instance
		static TextureManager* instance;
		map<string, SDL_Texture*> texturemap_;
};
