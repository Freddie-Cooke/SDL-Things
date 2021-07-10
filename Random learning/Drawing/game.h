// game.h, Freddie Cooke
// header file for the game class, defines games loops and updates

#include <time.h>
#include <stdlib.h>

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

		// Other
		// Random
		int getRandomInt();
		void drawline(int p1_x, int p1_y, int p2_x, int p2_y, int* color);

		// Accessors
		bool running() { return g_bRunning_; }
		SDL_Renderer* renderer() { return g_pRenderer_; }
		SDL_Window* window() { return g_pWindow_; }

		// Mutators
		void setRunning( bool value ) { g_bRunning_ = value; }

	private:
		bool g_bRunning_ = true;
		SDL_Window* g_pWindow_;
		SDL_Renderer* g_pRenderer_;
};
