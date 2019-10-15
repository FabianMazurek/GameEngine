#include "Game.h"
#include "SDL.h"
#include <stdio.h>
#include "bitmap.h"


Game::Game() 
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	SDL_Init(SDL_INIT_VIDEO);

	m_Window = SDL_CreateWindow(
		"My First Window", //title
		250,			   // initial x position	
		50,					//initial y position
		640,				//width in pixels
		480,				//height in pixels
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

	m_monster = new Bitmap(m_Renderer, "assets/monster.bmp", 100, 100);
	m_monsterTrans = new Bitmap(m_Renderer, "assets/monsterTrans.bmp", 200, 100);
	m_monsterTransKeyed = new Bitmap(m_Renderer, "assets/monsterTransKeyed.bmp", 300, 100, true);
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

void Game::Update(void)
{
	CheckEvents();

	SDL_RenderClear(m_Renderer);

	m_monster->draw();
	m_monsterTrans->draw();
	m_monsterTransKeyed->draw();

	SDL_RenderPresent(m_Renderer);

	SDL_Delay(16);
}

Game::~Game() 
{
	if (m_monsterTransKeyed)
		delete m_monsterTransKeyed;
	if (m_monsterTrans)
		delete m_monsterTrans;
	if (m_monster)
		delete m_monster;

	if (m_Renderer) {
		SDL_DestroyRenderer(m_Renderer);

	}

	if (m_Window) {
		SDL_DestroyWindow(m_Window);
	}
}