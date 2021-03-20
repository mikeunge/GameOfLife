#include "input.h"

bool getInput() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT){
            return true;
        }
        switch(e.type) {
            case SDL_KEYDOWN:
                switch(e.key.keysym.sym){
                    case SDLK_q:
                    case SDLK_ESCAPE:
                        return true;
                        break;
                    case SDLK_F1:
                    // TODO: add statistic information...
                        printf("Stats active");
                        fflush(stdout);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return false;
}
