#include "../puzzle_game.h"

void _Movement(SDL_Rect *player, SDL_Event *event)
{
	int nx, ny;
	int dx, dy;
	dx = 0;
	dy = 0;
	nx = player->x;
	ny = player->y;
	if (event->type != SDL_KEYDOWN) return ;
	if (event->key.keysym.sym == SDLK_d)
		dx = GRID;
	if (event->key.keysym.sym == SDLK_a)
		dx = -GRID;
	if (event->key.keysym.sym == SDLK_s)
		dy = GRID;
	if (event->key.keysym.sym == SDLK_w)
		dy = -GRID;

	nx += dx;
	ny += dy;
	if (isWall(nx, ny)) return;
	int bi = boxPos(nx, ny);
	if (bi != -1)
	{
		int bx = boxes[bi].x;
		int by = boxes[bi].y;
		bx += dx;
		by += dy;
		if (isWall(bx, by)) return;
		int bi2 = HasColl(bi,bx, by);
		if (bi2 != -1)
		{
			int bx2 = boxes[bi2].x;
			int by2 = boxes[bi2].y;
			bx2 += dx;
			by2 += dy;
			if (HasColl(bi2, bx2, by2) != -1 || isWall(bx2, by2)) return;
			boxes[bi2].x = bx2;
			boxes[bi2].y = by2;
		}
		boxes[bi].x = bx;
		boxes[bi].y = by;
	}
	player->x += dx;
	player->y += dy;
}
