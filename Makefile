CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c90
LDFLAGS = -lSDL2 -lSDL2_image -lm
OBJ = main.o input.o render.o walls.o map.o minimap.o textures.o

maze: $(OBJ)
	$(CC) $(CFLAGS) -o maze $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o maze
