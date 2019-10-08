#include "Game.h"
#include "SDL.h"
#include <stdio.h>

Game::Game() {
	m_Window = nullptr;
	m_Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	m_Window = SDL_CreateWindow(
		"My First Window",
		250,
		50,
		640,
		480,
		0
	);

	if (!m_Window) {
		printf("FAIL", SDL_GetError());
		printf("press the 8 key specifically\n");
		getchar();
		return;
	}

	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		0

	);

	if (!m_Renderer) {
		printf("Failed", SDL_GetError());
		printf("press the 69 key specifically!");
		getchar();

		return;
		
	}
}

void Game::SetDisplayColour(int x, int y)
{
	if (m_Renderer) 
	{
		int result = SDL_SetRenderDrawColor(
			m_Renderer,
			x,
			y,
			0,
			255
		);
		SDL_RenderClear(m_Renderer);

		SDL_RenderPresent(m_Renderer);


	}

}



Game::~Game() {
	if (m_Renderer) {
		SDL_DestroyRenderer(m_Renderer);

	}

	if (m_Window) {
		SDL_DestroyWindow(m_Window);
	}
}