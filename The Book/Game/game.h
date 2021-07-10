// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#include "SDL.h"

class Game {

	public:

		// Initilise SDL Window Renderer
		bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
		// Update the renderer
		void render();
		// Donno
		void update();
		// Event loop
		void handleEvents();
		// Clean pointers
		void clean();

		// Accessors
		bool running() { return g_bRunning_; }

		// Mutators
		void setRunning( bool value ) { g_bRunning_ = value; }

	private:
		bool g_bRunning_ = true;
		SDL_Window* g_pWindow_;
		SDL_Renderer* g_pRenderer_;
};
