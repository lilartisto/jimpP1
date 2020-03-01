#include <stdio.h>
#include "rules.h"
#include "printFile.h"
#include "map.h"

void main(int argc, char **argv)
{
    StateT state1;
    StateT state2;
    int width;
    int height;

    FILE *in = argc > 1 ? fopen(argv[1], "r") : fopen("data.txt", "r");

    if( in == NULL )
    {
        fprintf(stderr, "Blad, nie moge czytac z pliku\n");
        return;
    }
    
    fscanf(in, "%d %d", &width, &height);
    initState(&state1, width, height);
    initState(&state2, width, height);
    fileToState(&state1, in);

    next_round(&state1, &state2);

    writeState(&state2, stdout);

    freeState(&state1);
    freeState(&state2);
}