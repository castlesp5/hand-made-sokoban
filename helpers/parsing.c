#include "../puzzle_game.h"

void _randomizeMap()
{
	struct dirent *entry;
	DIR *dir = opendir("./zones");
	if (!dir) {fprintf(stderr, "FAILED TO OPEN ./zones directory :(");}

	while ((entry = readdir(dir)) != NULL)
	{
		char *dng = strrchr(entry->d_name, '.');
		if (dng && strcmp(dng, ".dng") == 0)
			files[counter++] = strdup(entry->d_name);
	}
}

void _parseMap()
{
	char path[256] = "./zones/";
	strcat(path, files[level]);
	int fd = open(path, O_RDONLY);
	char c;
	int x = 0;
	int y = 0;
	if (fd == -1)
	{
		fprintf(stderr, "Failed to load the map :(\n");	
		exit(2);
	}
	while(read(fd, &c, 1))
	{
		if (c == '\n') {y++; x = 0; continue;}
		if (x < WIDTH && y < HEIGHT)
			map[y][x] = c - '0';
		x++;
	}
	close(fd);
}

void _ParseBoxes()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == 2)
			{
				boxes[box_count].x = x * GRID;
				boxes[box_count].y = y * GRID;
				boxes[box_count].w = GRID;
				boxes[box_count].h = GRID;
				map[y][x] = 0;
				box_count++;
			}
		}
	}
}

void _ParseWin()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for(int x = 0; x < WIDTH; x++)
		{
			if (map[y][x] == 3)
			{
				win[win_count].x = 	x * GRID;
				win[win_count].y = y * GRID;
				win[win_count].h = GRID;
				win[win_count].w = GRID;
				win_count++;
				map[y][x] = 0;
			}
		}
	}
}
