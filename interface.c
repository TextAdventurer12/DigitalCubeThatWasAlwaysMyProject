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
void displayFace(Cube* cubeState, int face)
{
    loop(i, 3)
    {
        loop(j, 3)
        {
            printf("%s %d", setBackground(face), cubeState->arr[(face * 9) + (j + i * 3)].colour);
        }
        printf("%s", setBackground(-1));
        printf("\n");
    }
}
Cube* rotateFace(Cube* cubeState, int face, int degrees)
{
    loop (i, 9)
    {
        sticker this = cubeState->arr[i + face*9];
        float2 nextPos = rotate((float2){this.x, this.y}, degrees);
        cubeState->arr[i + face*9].x = nextPos.x;
        cubeState->arr[i + face*9].x = nextPos.y;
    }
    return cubeState;
}
// I DONT WANT TO PLAY AMONG US
void displayCube(Cube* cubeState)
{
    loop(i,6) displayFace(cubeState, i);
    int rotationAmounts[6] = {90, 180, 180, 0, 90, 0};
    loop(i, 6)
    {
        rotateFace(cubeState, i, rotationAmounts[i]);
    }
    loop(i, 3)
    {
        printf("      ");
        loop(j ,3)
        {
            printf("%s", setBackground(cubeState->arr[j+i*3+(GREEN*9)].colour));
            printf("%d ", cubeState->arr[j+i*3+(GREEN*9)].colour);
       }
        printf("%s", setBackground(-1));
        printf("\n");
    }
    int faces[4] = { RED, YELLOW, ORANGE, WHITE};
    loop(i, 3)
    {
        loop(j, 4)
        {
            loop(k, 3)
            {
                printf("%s", setBackground(cubeState->arr[k+i*3+(faces[j]*9)].colour));
                printf("%d ", cubeState->arr[k+i*3+(faces[j]*9)].colour);
            }
        }
        printf("%s", setBackground(-1));
        printf("\n");
    }
    loop(i, 3)
    {
        printf("      ");
        loop(j ,3)
        {
            printf("%s", setBackground(cubeState->arr[j+i*3+(BLUE*9)].colour));
            printf("%d ", cubeState->arr[j+i*3+(BLUE*9)].colour);
       }
        printf("%s", setBackground(-1));
        printf("\n");
    }
    loop(i, 6)
    {
	rotateFace(cubeState, i, 360-rotationAmounts[i]);
    }
    //printf("      %d %d %d\n");
    //printf("      %d %d %d\n");
    //printf("      %d %d %d\n");
    //printf("%d %d %d %d %d %d %d %d %d %d %d %d\n");
    //printf("%d %d %d %d %d %d %d %d %d %d %d %d\n");
    //printf("%d %d %d %d %d %d %d %d %d %d %d %d\n");
    //printf("      %d %d %d\n");
    //printf("      %d %d %d\n");
    //printf("      %d %d %d\n");
    //printf("-----------------------------------\n");
}

movePointer charToFunc(char funcType, char prime)
{
    char funcNames[6] = { 'R', 'L', 'U', 'D', 'F', 'B' };
    movePointer susbus[12] = { R, L, U, D, F, B, RP, LP, UP, DP, FP, BP};
    int index = -1;
    loop(i, 6) if (funcType == funcNames[i]) index = i + (prime * 6);
    printf("%d\n", index);
    return susbus[index];
}
movePointerVector* stringToFunc(charVector* funcType, charVector* prime)
{
    if (funcType->len != prime->len) exit(2);
    make_vec(demonWaifus, movePointerVector);
    loop(i, funcType->len)
    {
        push_back(demonWaifus, charToFunc(funcType->arr[i], prime->arr[i]));
    }
    return demonWaifus;
}
