#include "map.h"
#include "neighborhood.h"
#include "printFile.h"

void main(int argc, char** argv)
{
    StateT state;
    int width;
    int height;

    FILE *in = argc > 1 ? fopen(argv[1], "r") : fopen("data2.txt", "r");
    
    /* 0 0 1 0
       0 0 0 1 
       1 1 0 0
       0 0 1 0 */

    if( in == NULL )
    {
        fprintf(stderr, "Blad, nie moge czytac z pliku\n");
        return;
    }

    fscanf(in, "%d %d", &width, &height);
    initState(&state, width, height);
    fileToState(&state, in);
    writeState(&state, stdout);
    int counter;
    int x = 4;
    int y = 2;
    counter = count_neighborhood(&state, x, y);
    printf("Liczba sasiadow punktu o wspolrzednych x = %d i y = %d jest rowna %d", x, y, counter);

    freeState(&state);
}