#include "../include/core/app.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void createWindow(app *handle)
{
    handle->window = SDL_CreateWindow(handle->title,
     SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
       handle->windowWidth, 
       handle->windowHeight, 
       0);

    if (!handle->window) {
        printf("Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }
}

void createRenderer(app *handle)
{
    handle->renderer = SDL_CreateRenderer(handle->window, -1, 0);
}

app *createApp(uint16_t width, uint16_t height, char * _title)
{
    app *handle = (app *) malloc(sizeof(app));
    handle->windowWidth = width;
    handle->windowHeight = height;
    handle->isRunning = true;
    uint16_t _title_len = strlen(_title);
    handle->title = (char *) malloc(_title_len);
    strcpy(handle->title, _title);

    // create window
    createWindow(handle);
    // create renderer
    createRenderer(handle);

    return handle;
}

void destroyApp(app *handle)
{
    SDL_DestroyWindow(handle->window);
    SDL_Quit();
    free(handle);
}

