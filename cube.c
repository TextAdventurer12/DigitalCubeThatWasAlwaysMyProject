#include "cube.h"
#include <math.h>
#include <stdio.h>
#include "vector.h"

Cube* makeCube()
{
    make_vec(cubeState, Cube);
    loop(i, 6)
    {
        loop(j, 3)
        {
            loop(k, 3)
            {
                sticker _stck = (sticker){k, j,  i, i};
                push_back(cubeState, _stck);
            }
        }
    }
    return cubeState;
}

intVector* getUID(Cube* cubeState)
{
    make_vec(ids, intVector);
    for (int i = 0; i < cubeState->len; i++)
    {
        sticker* this = &cubeState->arr[i];
        if (this->y == 0 && this->face != YELLOW && this->face != WHITE)
        {
            push_back(ids,  i);
        }
    }
    //MEETS_CONDITION(cube, ids, this.y == 0 && this.face != YELLOW && this.face != WHITE);
    return ids;
}
intVector* getFID(Cube* cubeState)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cubeState, ids, (this.face == WHITE && this.y == 0) || (this.face == YELLOW && this.y == 2) || (this.face == RED && this.x == 2) || (this.face == ORANGE && this.x == 0));
    return ids;
}
intVector* getDID(Cube* cubeState)
{
    make_vec(ids ,intVector);
    MEETS_CONDITION(cubeState, ids, this.y == 2 && this.face != YELLOW && this.face != WHITE);
    return ids;
}
intVector* getBID(Cube* cubeState)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cubeState, ids, (this.face == WHITE && this.y == 2) || (this.face == YELLOW && this.y == 0) || (this.face == RED && this.x == 0) || (this.face == ORANGE && this.x == 2));
    return ids;
}
intVector* getRID(Cube* cubeState)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cubeState, ids, (this.face == GREEN && this.x == 2) || (this.x == 0 && this.face != RED && this.face != ORANGE && this.face != GREEN));
    return ids;
}
intVector* getLID(Cube* cubeState)
{
    make_vec(ids, intVector);
    MEETS_CONDITION(cubeState, ids, (this.face == GREEN && this.x == 0) || (this.x == 2 && this.face != RED && this.face != ORANGE && this.face != GREEN));
    return ids;
}

intVector* getID (Cube* cubeState, movePointer f)
{
    if (f == U || f == UP) return getUID(cubeState);
    if (f == D || f == DP) return getDID(cubeState);
    if (f == F || f == FP) return getFID(cubeState);
    if (f == B || f == BP) return getBID(cubeState);
    if (f == L || f == LP) return getLID(cubeState);
    if (f == R || f == RP) return getRID(cubeState);
    exit(1);
}

intVector* getFaceID(Cube* cubeState, int face)
{
    make_vec(ids, intVector);
    //MEETS_CONDITION(cubeState, ids, this.face == face);
    for (int i = 0; i < cubeState->len; i++)
    {
        sticker this = cubeState->arr[i];
        if (this.face == face)	{push_back(ids, i);}
    }
    make_vec(out, intVector);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < ids->len; k++)
            {
                if (cubeState->arr[ids->arr[k]].x == j && cubeState->arr[ids->arr[k]].y == i)
                {
                    push_back(out, ids->arr[k]);
                }            
            }
        }
    }
    destroy_vec(ids)
    return out;
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
    return value;
}
int2 flip  (int2 pos) { return (int2){2-pos.x, 2-pos.y}; }
int2 morphX(int2 pos) { return (int2){pos.y, 2 - pos.x}; }
int2 morphY(int2 pos) { return (int2){2 - pos.y, pos.x}; }
int2 remain(int2 pos) { return pos; }

sticker R (sticker x)
{
    fixedTranslate funcs[6] = {flip, remain, remain, flip, remain, remain};
    int face = roll(x.face - 1, 4);
    int2 _o = {x.x, x.y};
    _o = funcs[x.face](_o);
    return (sticker){_o.x, _o.y, face, x.colour};
}
sticker F (sticker x)
{
    fixedTranslate funcs[6] = {morphY, remain, morphY, remain, morphY, morphY};
    float y = 0;
    float c[6] = { 5, -16.0167, 18.2917, -7.4167, 1.2083, -0.0667};
    int2 outPos = funcs[x.face]((int2){x.x, x.y});
    POLYNOMIAL(6, y, x.face, c);
    return (sticker){outPos.x, outPos.y, roundf(y), x.colour};
}
sticker UP(sticker x)
{
    float y = 0;
    float c[6] = { 0, 23.1167, -33.125, 17.5833, -3.875, 0.3};
    POLYNOMIAL(6, y, x.face, c);
    return (sticker){ x.x, x.y, roundf(y), x.colour};
}
sticker RP(sticker x) { return R(R(R(x))); }
sticker L (sticker x) { return R(x); }
sticker LP(sticker x) { return L(L(L(x))); }
sticker U (sticker x) { return UP(UP(UP(x))); }
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

Cube* shift(Cube* cubeState, movePointer move)
{
    intVector* targetIDs = getID(cubeState, move);
    intVector* faceIDs = getFaceID(cubeState, getFace(move));
    printf("%d, %d\n", targetIDs->len, faceIDs->len);
    loop(i, targetIDs->len)
    {
        sticker* this = &cubeState->arr[targetIDs->arr[i]];
        *this = move(*this);
    }
    destroy_vec(targetIDs);
    loop(i, faceIDs->len)
    {
        sticker* this = &cubeState->arr[faceIDs->arr[i]];
        float2 dest = rotate((float2){this->x, this->y}, getRotation(move));
        *this = (sticker){roundf(dest.x), roundf(dest.y), this->face, this->colour};
    }
    destroy_vec(faceIDs);
    return cubeState;
}
