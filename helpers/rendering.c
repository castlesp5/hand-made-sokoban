#include "../puzzle_game.h"

void _RenderMap(SDL_Renderer *renderer)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			SDL_Rect wall = {x * GRID, y * GRID, GRID, GRID};
			if (map[y][x] == 1)
				SDL_SetRenderDrawColor(renderer, 255, 204, 255, 255);
			else 
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderFillRect(renderer, &wall);
		}
	}
}

void _RenderBoxes(SDL_Renderer *renderer)
{
	for (int y = 0; y <= box_count; y++)
	{
		SDL_SetRenderDrawColor(renderer, 102, 52, 0, 255);
		SDL_RenderFillRect(renderer, &boxes[y]);
	}
}

void _RenderWin(SDL_Renderer *renderer)
{
	for (int i = 0; i < win_count; i++)
	{
		SDL_SetRenderDrawColor(renderer, 76, 0, 153, 255);
		SDL_RenderFillRect(renderer, &win[i]);
	}
}


