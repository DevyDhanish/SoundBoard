#include "../include/core/canvas.h"
#include "../include/core/box.h"
#include "../include/core/app.h"
#include "../include/core/color.h"
#include "../include/core/render.h"
#include "../include/SDL2/SDL.h"
#include <stdio.h>
#include <stdlib.h>

void addBox(canvas *can, box *b)
{
    if(can->boxCount > can->maxBoxCount)
    {
        printf("Maximum amount of boxes reached, no more allowed\n");
        return;
    }

    can->boxes[can->boxCount] = b;
    can->boxCount += 1;
}

canvas *createCanvas(uint8_t mBC, uint16_t cW, uint16_t cH)
{
    canvas *can = (canvas *) malloc(sizeof(canvas));

    if(!can) 
    {
        printf("Failed to create a canvas\n");
        return NULL;
    }

    can->boxes = (box **) malloc(sizeof(box) * mBC);

    if(!can->boxes)
    {
        printf("Failed to allocate memory for box grind\n");
        return NULL;
    }

    can->boxCount = 0;
    can->canvasWidth = cW;
    can->canvasHeight = cH;
    can->maxBoxCount = mBC;

    return can;
}

void destroyCanvas(canvas *can)
{
    if(!can)
    {
        printf("Cannot remove something that does not exist\n");
        return;
    }

    while(can->boxCount)
    {
        destroyBox(can->boxes[can->boxCount]);
        can->boxCount -= 1;
    }

    free(can);
}

void drawCanvas(canvas *can, app *a)
{
    if(!can)
    {
        printf("No canvas specified\n");
    }

    SDL_Rect rect;

    rect.x = 100;
    rect.y = 100;
    rect.w = (int) can->canvasWidth;
    rect.h = (int) can->canvasHeight;

    SDL_SetRenderDrawColor(a->renderer, DARK_GRAY_43.r, DARK_GRAY_43.g, DARK_GRAY_43.b, DARK_GRAY_43.a);
    SDL_RenderFillRect(a->renderer, &rect);
    //SDL_RenderPresent(a->renderer);
    //paintColorFill(a->renderer, DARK_GRAY);
}