#include <stdio.h>
#include "interface.h"
#include "colours.h"

void displayFace(cube* cube, int face)
{
    loop(i, 3)
    {
        loop(j, 3)
        {
            printf("%s %d", setBackground(face), cube->arr[(face * 9) + (j + i * 3)].colour);
        }
        printf("\n");
    }
    printf("\n");
}

void displayCube(cube* cube)
{
    loop(i, 9)
    {
        displayFace(cube, i);
    }
    printf("-----------------------------------\n");
}