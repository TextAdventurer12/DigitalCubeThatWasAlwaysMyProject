#include "vector.h"
#include "general.h"
#include "cube.h"
#include "interface.h"
#include <stdio.h>

int main(void)
{
    cube* cube = makeCube();
    displayCube(cube);
    printf("Made Cube\n");
    UP((sticker){0, 0, 0, 0});
    //shift(cube, U);
    return 0;
}