#include "common.h"
#include "draw.h"
#include "game.h"


bool initSDL(SDL_Window *window, SDL_Renderer* *renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Could not initialize SDL!\n");
        return 1;
    }

    window = SDL_CreateWindow(
        "Convay's Game of Life",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        0
    );
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return false;
    }
    *renderer = SDL_CreateRenderer(window, -1, 0);
    return true;
}

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer* renderer = NULL;
    bool quit = false;

    if (initSDL(window, &renderer) == false) {
        return 1;
    }

    /* CellList c; */

    // gameloop
    while (!quit) {
        prepareScene(renderer);
        drawGrid(renderer);

        quit = run(renderer);

        presentScene(renderer);
        SDL_Delay(200);
    }

    // SDL cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

