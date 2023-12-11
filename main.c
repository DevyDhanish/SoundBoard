#include <stdio.h>
#include "include/SDL2/SDL.h"
#include "include/core/app.h"

int SDL_main(int argc, char **argv) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }

    app *App = createApp(300, 480, "Sound Board");

    while(App->isRunning) {};

    destroyApp(App);
    return 0;
}
