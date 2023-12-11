#ifndef RENDER_H
#define RENDER_H

#include "../SDL2/SDL.h"
#include "color.h"

void paintColorFill(SDL_Renderer *handle_renderer, color _col)
{
    SDL_SetRenderDrawColor(handle_renderer, _col.r, _col.g, _col.b, _col.a);
    SDL_RenderClear(handle_renderer);
}

#endif