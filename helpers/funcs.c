#include "../puzzle_game.h"

int isWall(int x, int y)
{
	int tx = x / GRID;
	int ty = y / GRID;

	if (tx < 0 || tx > WIDTH || ty <= 0 || ty >= HEIGHT)
		return 1;
	return map[ty][tx] == 1;
}

int boxPos(int x, int y)
{
	for (int i = 0; i < box_count; i++)
	{
		if (boxes[i].x == x && boxes[i].y == y)
			return i;
	}
	return -1;
}

int HasColl(int ind, int x, int y)
{
	SDL_Rect box = {x, y, GRID, GRID};
	for (int i = 0; i < box_count; i++)
	{
		if (i == ind) continue;
		if (SDL_HasIntersection(&boxes[i], &box))
			return i;
	}
	return -1;
}

int checkWin()
{
	didWin = 0;
	for (int i = 0; i < win_count; i++)
	{
		for (int j = 0; j < box_count; j++)
		{
			if (SDL_HasIntersection(&win[i], &boxes[j]))
			{didWin++; break;}
		}
	}
	return didWin;
}
