#include <stdio.h>
#include "interface.h"
#include "colours.h"
#include "vector.h"

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
    loop(i, 6)
    {
        displayFace(cube, i);
    }
    printf("-----------------------------------\n");
}

movePointer charToFunc(char funcType, char prime)
{
    char funcNames[6] = { 'R', 'L', 'U', 'D', 'F', 'B' };
    movePointer susbus[12] = { R, L, U, D, F, B, RP, LP, UP, DP, FP, BP};
    loop(i, 6)
    {
        if (funcType == funcNames[i])
        {
            return susbus[i + (prime * 6)];
        }
    }
    return -1;
}
movePointerVector stringToFunc(charVector funcType, charVector prime)
{
    if (funcType->len != prime->len) exit(2);
    make_vec(demonWaifus, movePointerVector);
    loop(i, funcType->len)
    {
        push_back(demonWaifus, charToFunc(funcType->arr[i], prime->arr[i]));
    }
    return demonWaifus;
}