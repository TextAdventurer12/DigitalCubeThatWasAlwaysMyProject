#ifndef CUBE_H
#define CUBE_H

#include "vector.h"

#define WHITE 0
#define BLUE 1
#define YELLOW 2
#define GREEN 3
#define ORANGE 4
#define RED 5

#define POLYNOMIAL(degree, y, x, c) loop(i, degree) y+=c[i]*pow(x,i)
#define MEETS_CONDITION(in, out, condition)         \
        loop(i, in->len)                            \
        {                                           \
            typeof(in->arr[0]) this = in->arr[i];   \
            if (condition) push_back(out, i)        \
        }

typedef struct
{
    int x;
    int y;
    int face;
    int colour;
} sticker;
namedVector(sticker, cube);
vector(cube);
// custom cube vector functions
void destroyCubeVector(cubeVector* this);

typedef struct
{
    int x;
    int y;
} int2;
vector(int2);
typedef struct
{
    float x;
    float y;
} float2;
vector(float2);

typedef sticker (*movePointer)(sticker);
typedef int2 (*fixedTranslate)(int2);

cube* makeCube();
cube* shift(cube* cube, movePointer move);
int2 morphY(int2 pos);
int2 morphX(int2 pos);
int2 flip  (int2 pos);
int2 remain(int2 pos);
sticker R (sticker x);
sticker RP(sticker x);
sticker L (sticker x);
sticker LP(sticker x);
sticker U (sticker x);
sticker UP(sticker x);
sticker D (sticker x);
sticker DP(sticker x);
sticker F (sticker x);
sticker FP(sticker x);
sticker B (sticker x);
sticker BP(sticker x);
intVector* getID (cube* cube, movePointer f);
intVector* getRID(cube* cube);
intVector* getUID(cube* cube);
intVector* getDID(cube* cube);
intVector* getFID(cube* cube);
intVector* getLID(cube* cube);
intVector* getBID(cube* cube);
intVector* getFaceID(cube* cube, int face);
int getFace(movePointer f);
int roll(int value, int max);
int getRotation(movePointer f);
float2 rotate(float2 pos, int degrees);

#endif