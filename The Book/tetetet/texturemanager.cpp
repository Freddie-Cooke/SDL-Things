// texturemanager.cpp, Freddie Cooke
// defines methods for drawing and loading textures

#include "texturemanager.h"

TextureManager* TextureManager::instance = 0;

bool TextureManager::load(string filename, string id, SDL_Renderer* renderer) {

	// Load image into memory
	SDL_Surface* temp_surface = IMG_Load(filename.c_str());

	// If image fails to load, clean and exit main
	if(!temp_surface) {
		cout << "Failed to load image: " << IMG_GetError(); return false;
	}

	// Create texture
	SDL_Texture* texture_ = SDL_CreateTextureFromSurface(renderer, temp_surface);

	SDL_FreeSurface(temp_surface); // Free temporary memory

	if (!texture_) { cout << "Failed to create texture:" << SDL_GetError() << endl; return false; }

	texturemap_[id] = texture_;
	cout << "Image loaded successfully." << endl;
	return true;
}

void TextureManager::draw(string id, int x, int y, int w, int h, SDL_Renderer* renderer, SDL_RendererFlip flip) {
	SDL_Rect srcRect, destRect;

	srcRect.x = srcRect.y = 0; // texture begins at 0,0
	destRect.x = x; destRect.y = y;

	srcRect.w = destRect.w = w; 
	srcRect.h = destRect.h = h;

	SDL_RenderCopyEx(renderer, texturemap_[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::drawFrame(string id, int x, int y, int w, int h, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip) {

	SDL_Rect srcRect, destRect;

	srcRect.x = w * (currentFrame); // Manage the frame
	srcRect.y = h * (currentRow -1); // Manage row of frame

	srcRect.w = destRect.w = w; // Assign width and height
	srcRect.h = destRect.h = h;

	destRect.x = x; // Leave renderer position for other places
	destRect.y = y;

	// Draw the current frame
	SDL_RenderCopyEx(renderer, texturemap_[id], &srcRect, &destRect, 0, 0, flip);
}
