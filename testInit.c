#include "printFile.h"
#include "map.h"
#include <stdio.h>

void main()
{
    StateT state;
    int width = 10;
    int height = 10;
    initState(&state, width, height);
    writeState(&state, stdout);
    freeState(&state);

}