#ifndef COLOR_H
#define COLOR_H

#include <stdint.h>

struct COLOR 
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

typedef struct COLOR color;

extern const color RED;
extern const color GREEN;
extern const color BLUE;
extern const color WHITE;
extern const color DARK_GRAY;
extern const color DARK_GRAY_43;

#endif