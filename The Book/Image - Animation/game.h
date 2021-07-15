// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#include "SDL.h"

class Game {

	public:

		// Initilise SDL Window Renderer
		bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		// Update the renderer
		void render();
		// Donno
		void update();
		// Event loop
		void handleEvents();
		// Clean pointers
		void clean();

		// Accessors
		bool running() { return running_; }

		// Mutators
		void setRunning( bool value ) { running_ = value; }

	private:
		bool running_;
		SDL_Window* window_;
		SDL_Renderer* renderer_;

		int color_int_ = 0;

		SDL_Texture* texture_;
		SDL_Rect sourceRect_, destRect_;
};
