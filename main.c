#include <stdio.h>
#include "include/SDL2/SDL.h"
#include "include/core/app.h"
#include "include/core/render.h"
#include "include/core/color.h"
#include "include/core/canvas.h"
#include "include/core/box.h"

int SDL_main(int argc, char **argv) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL initialization failed: %s\n", SDL_GetError());
        return 1;
    }


    app *App = createApp(300, 480, "Sound Board");

    box *b1 = makeBox("box 1");
    canvas *can = createCanvas(12, 200, 200);
    addBox(can, b1);

    while(App->isRunning)
    {
        getEvent(App);

        paintColorFill(App->renderer, DARK_GRAY);
        drawCanvas(can, App);
        switch (App->event.type)
        {
            case SDL_QUIT:
                destroyApp(App);
                return 0;
                break;
            
            default:
                break;
        }

        refreshView(App);
    };

    destroyCanvas(can);
    destroyApp(App);
    return 0;
}
