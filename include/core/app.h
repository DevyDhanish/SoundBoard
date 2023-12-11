#ifndef APP_H
#define APP_H

#include "../SDL2/SDL.h"
#include <stdbool.h>


struct APP
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    uint16_t windowHeight;
    uint16_t windowWidth;
    char *title;
    SDL_Event event;
    bool isRunning;
};

typedef struct APP app;

app *createApp(uint16_t w, uint16_t h, char *t);

void destroyApp(app *);

#endif