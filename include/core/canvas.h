#ifndef CANVAS_H
#define CANVAS_H

#include "box.h"
#include "app.h"
#include <stdint.h>

// it's gonna have 12 boxes with audio
struct CANVAS 
{
    box **boxes;
    uint8_t boxCount;
    uint8_t maxBoxCount; // 12
    uint16_t canvasWidth;
    uint16_t canvasHeight;
    // bg maybe a image idk
};

typedef struct CANVAS canvas;

void addBox(canvas *c, box *b);

canvas *createCanvas(uint8_t mBC, uint16_t cW, uint16_t cH);

void destroyCanvas(canvas *can);

void drawCanvas(canvas *can, app *a);

#endif