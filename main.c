#include "vector.h"
#include "general.h"
#include "cube.h"
#include "interface.h"
#include <stdio.h>

int main(void)
{
    Cube* cube = makeCube();
    //displayCube(cube);
    shift(cube, R);
    displayCube(cube);
    /*while (1)
    {
        displayCube(cube);
        printf("each cmd is two characters, the first is the face it affects {R L U D F B}, the second indicates the direction, space for clockwise and P for anticlockwise\n");
        char cmd[2];
        scanf("%2s", cmd);
        cube = shift(cube, charToFunc(cmd[0], cmd[1]=='P'));
    }*/
    return 0;
}
