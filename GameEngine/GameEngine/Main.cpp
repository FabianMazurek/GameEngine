#include "SDL.h"
#include <iostream>
#include "Game.h">
#undef main



void main (void)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Renderer *renderer{};
	int red;
	int green;


	bool quit = false;

	Game* game = new Game(); //Creates nmew hame mewtwo raids between 6-7.

	while (!quit) 
	{
		

		SDL_RenderClear(renderer);
		SDL_Event Event;
		while (SDL_PollEvent(&Event))
		{
			if (Event.type == SDL_KEYDOWN)
			{
				if (Event.key.keysym.sym == SDLK_q) 
				{
					quit = true;
				}
			}
			if (Event.type == SDL_MOUSEMOTION) 
			{
				int x, y;
				SDL_GetMouseState(&x, &y);
				std::cout << x << " " << y << std::endl;
				red = x;
				green = y;


				game->SetDisplayColour(x, y);
			}
		
		}
	}

	delete game;
	game = nullptr;

	SDL_Quit();
}