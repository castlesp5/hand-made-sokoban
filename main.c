#include "puzzle_game.h"

int map[HEIGHT][WIDTH];
char *files[100];
int level = 0;
int counter = 0;
SDL_Rect boxes[MAX_BOXES];
int box_count = 0;
SDL_Rect win[MAX_BOXES];
int win_count = 0;
int didWin = 0;

char str[] =
    ".__                       .___                            .___         _________________   ____  __.________ __________    _____    _______   \n"
    "|  |__ _____    ____    __| _/          _____ _____     __| _/____    /   _____/\\_____  \\ |    |/ _|\\_____  \\\\______   \\  /  _  \\   \\      \\  \n"
    "|  |  \\\\__  \\  /    \\  / __ |  ______  /     \\\\__  \\   / __ |/ __ \\   \\_____  \\  /   |   \\|      <   /   |   \\|    |  _/ /  /_\\  \\  /   |   \\ \n"
    "|   Y  \\/ __ \\|   |  \\/ /_/ | /_____/ |  Y Y  \\/ __ \\_/ /_/ \\  ___/   /        \\/    |    \\    |  \\ /    |    \\    |   \\/    |    \\/    |    \\\n"
    "|___|  (____  /___|  /\\____ |         |__|_|  (____  /\\____ |\\___  > /_______  /\\_______  /____|__ \\\\_______  /______  /\\____|__  /\\____|__  /\n"
    "     \\/     \\/     \\/      \\/               \\/     \\/      \\/    \\/          \\/         \\/        \\/        \\/       \\/         \\/         \\/ \n";

void mainMenu()
{
	int n;
	system("clear");
	while (1)
	{
		printf("\n\n%s\n\n", str);
		printf("Welcome to hand-made Sokoban !\n");
		printf("\n");
		printf("Push the 'brown' boxes into the 'purple frame' to win! \n\n");
		printf("Controls : \n<Q> Quit\n<R> Restart level\n<W> Move Up\n<S> Move Down\n<D> Move Right\n<A> Move Left\n\n");
		printf("1 - Start\n");
		printf("2 - Exit\n");
		printf("Your Choice : ");
		scanf("%d", &n);
		if (n == 2)
			exit(0);
		return ;
	}
}

int main()
{
	mainMenu();
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("hand-made Sokoban", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH * GRID, HEIGHT * GRID, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	SDL_Rect player = {GRID, GRID, GRID, GRID};
	int running = 1;
	int level_counter = 0;
	_randomizeMap();
	while (running && level_counter <= counter)
	{
		int levelEnded = 0;
		didWin = 0;
		win_count = 0;
		box_count = 0;
		memset(boxes, 0, sizeof(boxes));
		memset(win, 0, sizeof(win));
		player.x = GRID;
		player.y = GRID;
		_parseMap();
		_ParseBoxes();
		_ParseWin();
		while(!levelEnded)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_q) {running = 0; levelEnded = 1;}	
				if (event.key.keysym.sym == SDLK_r)
				{
					levelEnded = 1;
				}
				_Movement(&player, &event);
			}
			SDL_RenderClear(renderer);
			_RenderMap(renderer);
			_RenderWin(renderer);
			_RenderBoxes(renderer);
		    SDL_SetRenderDrawColor(renderer, 153, 0, 0, 255);
			SDL_RenderFillRect(renderer, &player);
			SDL_RenderPresent(renderer);
			checkWin();
			if (didWin == win_count)
			{
				levelEnded = 1;
				level_counter++;
				level++;
			}
			SDL_Delay(0);
		}
		if (level_counter >= counter)
			break;
	}
	for (int i = 0; i < counter; i++)
		free(files[i]);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	printf("Thanks for passing by :)\n");
}
