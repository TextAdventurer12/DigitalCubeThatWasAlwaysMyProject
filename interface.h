#ifndef INTERFACE_H
#define INTERFACE_H

#include "cube.h"
#include "vector.h"

vector(movePointer);

void displayFace(Cube* cube, int face);
void displayCube(Cube* cube);
movePointer charToFunc(char funcType, char prime);
movePointerVector* stringToFunc(charVector* funcTypes, charVector* primes);

#endif