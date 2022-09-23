#include "cube.h"
#include <math.h>
#include <stdio.h>
#include "vector.h"

cube* makeCube()
{
    make_vec(cube, cube);
    loop(i, 6)
    {
        loop(j, 3)
        {
            loop(k, 3)
            {
                sticker _stck = (sticker){k, j,  i, i};
                push_back(cube, _stck);
            }
        }
    }
}

intVector* getUID(cube* cube)
{
    make_vec(ids, intVector);
    for (int i = 0; i < cube->len; i++)
    {
        sticker* this = &cube->arr[i];
        printf("%d\n", i);
        if (this->y == 0 && this->face != YELLOW && this->face != WHITE)
        {
            push_back(ids,  i);
        }
    }
    //MEETS_CONDITION(cube, ids, this.y == 0 && this.face != YELLOW && this.face != WHITE);
    return ids;
}
intVector* getFID(cube* cube)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cube, ids, (this.face == WHITE && this.y == 0) || (this.face == YELLOW && this.y == 2) || (this.face == RED && this.x == 2) || (this.face == ORANGE && this.x == 0));
    return ids;
}
intVector* getDID(cube* cube)
{
    make_vec(ids ,intVector);
    MEETS_CONDITION(cube, ids, this.y == 2 && this.face != YELLOW && this.face != WHITE);
    return ids;
}
intVector* getBID(cube* cube)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cube, ids, (this.face == WHITE && this.y == 2) || (this.face == YELLOW && this.y == 0) || (this.face == RED && this.x == 0) || (this.face == ORANGE && this.x == 2));
    return ids;
}
intVector* getRID(cube* cube)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cube, ids, (this.face == GREEN && this.x == 2) || (this.x == 0 && this.face != RED && this.face != ORANGE && this.face != GREEN));
    return ids;
}
intVector* getLID(cube* cube)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cube, ids, (this.face == GREEN && this.x == 0) || (this.x == 2 && this.face != RED && this.face != ORANGE && this.face != GREEN));
    return ids;
}

intVector* getID (cube* cube, movePointer f)
{
    int face = f((sticker){0, 0, WHITE, WHITE}).face;
    switch (face)
    {
        case WHITE:
            return getUID(cube);
        case BLUE:
            return getFID(cube);
        case YELLOW:
            return getDID(cube);
        case GREEN:
            return getBID(cube);
        case ORANGE:
            return getRID(cube);
        case RED:
            return getLID(cube);
        default:
            exit(1);
    }
}

intVector* getFaceID(cube* cube, int face)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cube, ids, this.face == face);
    printf("sus\n");
    return ids;
}

int getFace(movePointer f)
{
    if (f == U || f == UP) return WHITE;
    if (f == D || f == DP) return YELLOW;
    if (f == F || f == FP) return BLUE;
    if (f == B || f == BP) return GREEN;
    if (f == L || f == LP) return RED;
    if (f == R || f == RP) return ORANGE;
    return -1;
}

int roll(int value, int max)
{
    while (value >= max) value -= max;
    while (value < 0) value += max;
}
int2 flip  (int2 pos)
{
    return (int2){2-pos.x, 2-pos.y};
}
int2 morphX(int2 pos) { return (int2){pos.y, 2 - pos.x}; }
int2 morphY(int2 pos) { return (int2){2 - pos.y, pos.x}; }
int2 remain(int2 pos) { return pos; }

sticker R (sticker x)
{
    fixedTranslate funcs[6] = {flip, remain, remain, flip, remain, remain};
    int2 outputPos = funcs[x.face]((int2){x.x,  x.y});
    int face = roll(x.face - 1, 4);
    return (sticker){x.x, x.y, face, x.colour};
}
sticker F (sticker x)
{
    fixedTranslate funcs[6] = {morphY, remain, morphY, remain, morphY, morphY};
    int2 outPos = funcs[x.face]((int2){x.x, x.y});
    float y = 0;
    float c[6] = { 5, -16.0167, 18.2917, -7.4167, 1.2083, -0.0667};
    POLYNOMIAL(6, y, x.face, c);
    return (sticker){outPos.x, outPos.y, roundf(y), x.colour};
}
sticker UP(sticker x)
{
    float y = 0;
    float c[6] = { 0, 27.6833, -38.9583, 20.4583, 0.3583 };
    POLYNOMIAL(6, y, x.face, c);
    return (sticker){ x.x, x.y, roundf(y), x.colour};
}
sticker RP(sticker x) { return R(R(R(x))); }
sticker L (sticker x) { return R(x); }
sticker LP(sticker x) { return L(L(L(x))); }
sticker U (sticker x) { return U(U(U(x))); }
sticker D (sticker x) { return U(x); }
sticker DP(sticker x) { return D(D(D(x))); }
sticker FP(sticker x) { return F(F(F(x))); }
sticker B (sticker x) { return B(x); }
sticker BP(sticker x) { return B(B(B(x))); }

int getRotation(movePointer f)
{
    return -((f == U || f == D || f == R || f == L || f == F || f == B) * 2 - 1) * 90;
}
float2 rotate(float2 pos, int degrees)
{

    //degrees *= (3.14159 / 180);
    float2 out;
    out = (float2){roundf((pos.x-1) * cos(degrees) - (pos.y-1) * sin(degrees) + 1), roundf((pos.y-1) * cos(degrees) + (pos.x-1) * sin(degrees) + 1)};
    return out;
}

cube* shift(cube* cube, movePointer move)
{
    printf("what the sus");
    intVector* targetIDs = getID(cube, move);
    printf("Line IDs got\n");
    intVector* faceIDs = getFaceID(cube, getFace(move));
    printf("Face IDs got\n");
    loop(i, targetIDs->len)
    {
        printf("%d\n", i);
        sticker* this = &cube->arr[targetIDs->arr[i]];
        *this = move(*this);
    }
    destroy_vec(targetIDs);
    loop(i, faceIDs->len)
    {
        sticker* this = &cube->arr[faceIDs->arr[i]];
        float2 dest = rotate((float2){this->x, this->y}, getRotation(move));
        *this = (sticker){roundf(dest.x), roundf(dest.y), this->face, this->colour};
    }
    destroy_vec(faceIDs);
    return cube;
}