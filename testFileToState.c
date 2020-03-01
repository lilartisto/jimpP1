#include "printFile.h"
#include "map.h"

#include <stdio.h>

void main(int argc, char **argv)
{
    StateT state;
    int width;
    int height;

    FILE *in = argc > 1 ? fopen(argv[1], "r") : fopen("data.txt", "r");

    if( in == NULL )
    {
        fprintf(stderr, "Blad, nie moge czytac z pliku\n");
        return;
    }
    fscanf(in, "%d %d", &width, &height);
    initState(&state, width, height);
    fileToState(&state, in);
    writeState(&state, stdout);

    freeState(&state);
}