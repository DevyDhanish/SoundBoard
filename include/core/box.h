#ifndef BOX_H
#define BOX_H

struct BOX
{
    char *title;
    // audio
};


typedef struct BOX box;

box *makeBox(char *_title);

void destroyBox(box *);

#endif