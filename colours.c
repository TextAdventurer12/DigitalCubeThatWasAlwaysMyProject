#include "colours.h"

char* setColour(int colour)
{
    if (colour == 0) { return WHT; }
    if (colour == 1) { return BLU; }
    if (colour == 2) { return YEL; }
    if (colour == 3) { return GRN; }
    if (colour == 4) { return MAG; }
    if (colour == 5) { return CRED; }
    else { return CRESET; }
}
char* setBackground(int colour)
{
    if (colour == 0) { return WHTB; }
    if (colour == 1) { return BLUB; }
    if (colour == 2) { return GRNB; }
    if (colour == 3) { return YELB; }
    if (colour == 4) { return MAGB; }
    if (colour == 5) { return REDB; }
    else { return CRESET; }
}