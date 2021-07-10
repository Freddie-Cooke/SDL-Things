// sdl_loop.cpp, Freddie Cooke
// SDL renderer and window abstracted

#include "SDL.h"

void Init(SDL_Window* &window, SDL_Renderer* &renderer) {

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"Window", // Window Title
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, // x, y, w, h
		SDL_WINDOW_SHOWN); // Uint32 flags

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black, max alpha
	SDL_RenderClear(renderer); // Clear with current colour
	SDL_RenderPresent(renderer); // Refresh the window
}

void Update();
void HandleEvents();
void Clean();

int main(int argc, char* argv[]) {

	SDL_Window* g_pWindow;
	SDL_Renderer* g_pRenderer;

	bool g_bRunning = true;

	// Initilisation, SDL, Window, Renderer
	Init(g_pWindow, g_pRenderer);

	// Game Loop
	while (g_bRunning) {
		Render(g_pRenderer);
		SDL_Delay(3000); // Wait 3 seconds
		g_bRunning = false;
	}

	SDL_Quit();

	return 0;
}
