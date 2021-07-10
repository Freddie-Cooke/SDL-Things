// hello_sdl.cpp, Freddie Cooke
// hello world using sdl

#include <iostream>
#include "SDL.h"

// Window and renderer objects
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

// Main
int main(int argc, char* args[]) {

	// Initilise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		// If init succsessful
		g_pWindow = SDL_CreateWindow(
			"Hello SDL", 
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			640, 480, 
			SDL_WINDOW_SHOWN);

		// Check if window creation was successful, if so create renderer.
		if (g_pWindow != 0) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, 0);
		}
	}
	else {
		// SDL Initilisation not successful.
		throw "SDL Could not be initilised.";
		return 1;
	}

	// Window configuration
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255); // Set clear screen colour to black
	SDL_RenderClear(g_pRenderer); // Clear the renderder with black colour
	SDL_RenderPresent(g_pRenderer); // Update the renderer
	SDL_Delay(5000); // Set a delay for 5000ms before exiting

	// Pause to see renderer

	system("pause");
	SDL_Quit();

	return 0;
}
