#include "../include/SDL2/SDL.h"
#include "../include/core/render.h"
#include "../include/core/color.h"

void paintColorFill(SDL_Renderer *handle_renderer, color _col)
{
    SDL_SetRenderDrawColor(handle_renderer, _col.r, _col.g, _col.b, _col.a);
    SDL_RenderClear(handle_renderer);
}