#ifndef GAME_H
#define GAME_H

#include "common.h"

typedef struct {
    int id;
    int x;
    int y;
    bool alive;
    int neighbors;
} Cell;

typedef struct {
    Cell *cell;
} CellList;

// Get the actual screen size;
//int grid_size = ((SCREEN_HEIGHT / MAGIC_NUMBER) + (SCREEN_WIDTH / MAGIC_NUMBER)) * 2; 

bool isAlive(Cell *cell);
int hasNeighbors(Cell *cell);
void createCell(SDL_Renderer* renderer, int x, int y);
void populateWorld(SDL_Renderer* renderer);
bool run(SDL_Renderer* renderer);

#endif  // GAME_H
