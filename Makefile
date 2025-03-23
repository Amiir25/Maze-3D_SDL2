CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -I.
LDFLAGS = -lSDL2 -lm

SRC = main.c map.c input.c render.c walls.c
OBJ = $(SRC:.c=.o)
TARGET = maze

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)
