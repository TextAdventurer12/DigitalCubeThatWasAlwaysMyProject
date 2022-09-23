#ifndef INTERFACE_H
#define INTERFACE_H

#include "cube.h"
#include "vector.h"

vector(movePointer);

void displayFace(cube* cube, int face);
void displayCube(cube* cube);
movePointer charToFunc(char funcType, char prime);
movePointerVector* stringToFunc(charVector funcTypes, charVector primes);

#endif