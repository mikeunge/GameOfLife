#include "draw.h"

int rand_color() {
    int num = (rand() % 
           (MAX_COLOR - MIN_COLOR + 1)) + MIN_COLOR;
    return num;
}

void drawRect(SDL_Renderer* renderer, SDL_Rect* rect) {
    SDL_SetRenderDrawColor(renderer, CELL_COLOR, CELL_COLOR, CELL_COLOR, 255);
    SDL_RenderDrawRect(renderer, rect);
    SDL_RenderFillRect(renderer, rect);
}

void drawLine(SDL_Renderer* renderer, Line *line) {
    SDL_RenderDrawLine(renderer, line->x1, line->y1, line->x2, line->y2);
}

void drawGrid(SDL_Renderer* renderer) {
    int max_lines_height = SCREEN_HEIGHT / MAGIC_NUMBER;
    int max_lines_width = SCREEN_WIDTH / MAGIC_NUMBER;
    int prev_height = MAGIC_NUMBER;
    int prev_width = MAGIC_NUMBER;

    SDL_SetRenderDrawColor(renderer, LINE_COLOR, LINE_COLOR, LINE_COLOR, 255);

    // draw horizontal lines
    for (int i = 0; i < max_lines_width; i++) {
        Line horizontal = {prev_height, 0, prev_height, SCREEN_HEIGHT};
        drawLine(renderer, &horizontal);
        prev_height = prev_height + MAGIC_NUMBER;
    }
    // draw vertical lines
    for (int i = 0; i < max_lines_height; i++) {
        Line vertical = {0, prev_width, SCREEN_WIDTH, prev_width};
        drawLine(renderer, &vertical);
        prev_width = prev_width + MAGIC_NUMBER;
    }
}

void prepareScene(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, BG_COLOR, BG_COLOR, BG_COLOR, 255);
    SDL_RenderClear(renderer);
}

void presentScene(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}
