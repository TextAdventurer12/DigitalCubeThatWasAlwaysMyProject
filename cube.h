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
            typeof(in->arr[i]) this = in->arr[i];   \
            if (condition) push_back(out, i)        \
        }

typedef struct
{
    int x;
    int y;
    int face;
    int colour;
} sticker;
namedVector(sticker, Cube);
typedef struct { sticker* arr; unsigned int len; } sus;
namedVector(sticker, face);
vector(Cube);

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

Cube* makeCube();
Cube* shift(Cube* cube, movePointer move);
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
intVector* getID (Cube* cube, movePointer f);
intVector* getRID(Cube* cube);
intVector* getUID(Cube* cube);
intVector* getDID(Cube* cube);
intVector* getFID(Cube* cube);
intVector* getLID(Cube* cube);
intVector* getBID(Cube* cube);
intVector* getFaceID(Cube* cube, int face);
int getFace(movePointer f);
int roll(int value, int max);
int getRotation(movePointer f);
float2 rotate(float2 pos, int degrees);

#endif