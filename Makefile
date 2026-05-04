SRCS = ./helpers/_movement.c \
			 ./helpers/funcs.c \
			 ./helpers/parsing.c \
			 ./helpers/rendering.c \
			 main.c

CFLAGS = $(shell pkg-config --cflags sdl2)
LIBS = $(shell pkg-config --libs sdl2)

all:
	cc $(SRCS) $(CFLAGS) $(LIBS) -o ./puzzle_game -Wall -Wextra -Werror
	./puzzle_game

clean:
	rm -rf ./puzzle_game
