#ifndef DRAW_H
#define DRAW_H

#include "common.h"

#define MAX_COLOR 255
#define MIN_COLOR 1

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Line;

int rand_color();
void drawRect(SDL_Renderer* renderer, SDL_Rect* rect);
void drawLine(SDL_Renderer* renderer, Line *line);
void drawGrid(SDL_Renderer* renderer);
void prepareScene(SDL_Renderer* renderer);
void presentScene(SDL_Renderer* renderer);

#endif  // DRAW_H
