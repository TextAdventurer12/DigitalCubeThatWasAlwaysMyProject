#include "vector.h"
#include "general.h"
#include "cube.h"
#include "interface.h"
#include <stdio.h>

int main(void)
{
    cube* cube = makeCube();
    displayCube(cube);
    return 0;
}