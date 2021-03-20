CC      = clang
CLFAGS  = -std=c99 -Wall -DDEBUG -g -O0 -fvisibility=hidden
CFLAGS  += -lSDL2main -lSDL2 

SRC     = $(wildcard src/*.c)
OBJ     = $(SRC:.c=.o)
BIN     = bin

.PHONY: all clean 

all: dirs game

dirs:
	mkdir -p ./$(BIN)

run: all
	$(BIN)/game

game: $(OBJ)
	$(CC) -o $(BIN)/game $^ $(CFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(BIN) $(OBJ)

