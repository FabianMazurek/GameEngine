#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>


struct SDL_Window;
struct SDL_Renderer;
class Bitmap;

class Game 
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	bool m_running;

	Bitmap* m_monster;
	Bitmap* m_monsterTrans;
	Bitmap* m_monsterTransKeyed;

	void CheckEvents();

public:
	Game();
	~Game();
	void Update(void);
	void SetDisplayColour(int x, int y);

};

#endif
