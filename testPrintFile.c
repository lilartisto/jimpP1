#include "printFile.h"
#include "map.h"

#include <stdio.h>

void main(int argc, char **argv)
{
    StateT state;
    int width;
    int height;
    char photoName[32];

    FILE *in = argc > 1 ? fopen(argv[1], "r") : fopen("data.txt", "r");

    if( in == NULL )
    {
        fprintf(stderr, "Blad, nie moge czytac z pliku\n");
        return;
    }
    fscanf(in, "%d %d", &width, &height);
    initState(&state, width, height);
    fileToState(&state, in);

	sprintf( photoName, "photo%d.png", 0 );
    process_file(&state);
    write_png_file( photoName );

    writeState(&state, stdout);

    freeState(&state);
}
