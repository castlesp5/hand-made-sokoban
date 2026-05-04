#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define GRID 60
#define HEIGHT 9
#define WIDTH 14
#define MAX_BOXES 100

extern int map[HEIGHT][WIDTH];
extern char *files[100];
extern int level;
extern int counter;
extern SDL_Rect boxes[MAX_BOXES];
extern int box_count;
extern SDL_Rect win[MAX_BOXES];
extern int win_count;
extern int didWin;


void _Movement(SDL_Rect *player, SDL_Event *event);
void	_randomizeMap();
int isWall(int x, int y);
int boxPos(int x, int y);
int HasColl(int ind, int x, int y);
int checkWin();
void _ParseWin();
void _ParseBoxes();
void _parseMap();
void _RenderMap(SDL_Renderer *renderer);
void _RenderBoxes(SDL_Renderer *renderer);
void _RenderWin(SDL_Renderer *renderer);

