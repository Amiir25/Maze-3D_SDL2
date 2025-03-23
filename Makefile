CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c90 -I/usr/include/SDL2 -D_REENTRANT
LDFLAGS = -lSDL2 -lSDL2_image -lm  # Added -lSDL2_image to fix the IMG_Load error

OBJ = main.o input.o map.o render.o walls.o textures.o

maze_game: $(OBJ)
	$(CC) $(OBJ) -o maze_game $(CFLAGS) $(LDFLAGS)

%.o: %.c maze.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o maze_game
