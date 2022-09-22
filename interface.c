#include <stdio.h>
#include "interface.h"
#include "colours.h"
#include "vector.h"

/*

      G G G
      G G G
      G G G
R R R Y Y Y O O O W W W
R R R Y Y Y O O O W W W
R R R Y Y Y O O O W W W
      B B B
      B B B
      B B B

*/
// this is basically fine just rotate the face so that 0, 0 is in the right spot beforehand
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
cube* rotateFace(cube* cube, int face, int degrees)
{
    loop (i, 9)
    {
        sticker this = cube[i + face*9];
        float2 nextPos = rotate({this.x, this.y}, degrees);
    }
}
// I DONT WANT TO PLAY AMONG US
void displayCube(cube* cube)
{
    cube astolfo = *cube;
    int rotationAmounts[6] = {90, 180, 180, 0, 90, 0};
    loop(i, 6)
    {

    }
    printf("-----------------------------------\n");
}

movePointer charToFunc(char funcType, char prime)
{
    char funcNames[6] = { 'R', 'L', 'U', 'D', 'F', 'B' };
    movePointer susbus[12] = { R, L, U, D, F, B, RP, LP, UP, DP, FP, BP};
    loop(i, 6) if (funcType == funcNames[i]) return susbus[i + (prime * 6)];
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