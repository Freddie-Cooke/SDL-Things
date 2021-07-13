// renderer.h

#pragma once

#include "SDL.h"
#include <vector>

class Renderer {

	public:

		// Const Dest
		Renderer(SDL_Window* window);
		~Renderer();

		// Accessors
		SDL_Renderer& renderer() { return *renderer_; }

		// Update renderer
		void update();

	private:
		SDL_Renderer* renderer_;
		std::vector<GameObject*> render_queue_;
};
