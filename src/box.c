#include "../include/core/box.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

box *makeBox(char *_title)
{
    box *bx = (box *) malloc(sizeof(box));

    if(!bx)
    {
        printf("Failed to allocate memory for box\n");
        return NULL;
    }

    bx->title = (char *) malloc(strlen(_title));
    strcpy(bx->title, _title);

    return bx;
}

void destroyBox(box *b)
{
    if(!b)
    {
        printf("Cannot remove something that does not exist\n");
    }

    free(b->title);
    free(b);
}