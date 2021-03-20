#include "game.h"
#include "draw.h"
#include "input.h"


bool isAlive(Cell *cell) {
    int neighbors = hasNeighbors(cell);
    if (neighbors == 2 || neighbors == 3) {
        cell->alive = true;
        cell->neighbors = neighbors;
        return true;
    }
    return false;
}

int hasNeighbors(Cell *cell) {
    return 1;
}

void createCell(SDL_Renderer* renderer, int x, int y) {
    SDL_Rect rect = {x, y, MAGIC_NUMBER, MAGIC_NUMBER};
    drawRect(renderer, &rect);
}

void populateWorld(SDL_Renderer* render) {

}

bool run(SDL_Renderer* renderer) {
    int y = 0;
    int x = 0;
    int id = 0;

    while (y < SCREEN_HEIGHT) {
        while (x < SCREEN_WIDTH) {
            createCell(renderer, x, y);

            printf("%d\n", id);
            fflush(stdout);
            id++;

            x = x + MAGIC_NUMBER;
            if (getInput() == true){
                return true;
            }
        }
        y = y + MAGIC_NUMBER;
        x = 0;
    }

    return false;
}
