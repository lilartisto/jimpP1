#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "printFile.h"
#include "rules.h"


int main( int argc, char **argv )
{
    //1 argument to ilosc iteracji
    //2 argument to plik
    //3 argument to do jakiego pliku zapisac stan
    int n = argc > 1 ? atoi( argv[1] ) : 5;
    FILE *in = argc > 2 ? fopen( argv[2], "r" ) : fopen( "data.txt", "r");
    StateT state1;
    StateT state2;
    int width;
    int height;
    bool first = 1; // czy pierwsza plansza
    char photoName[32];

    if( in == NULL )
    {
        fprintf(stderr, "Nie udalo sie otworzyc pliku wejsciowego\n");
        return -1;
    }

    fscanf( in, "%d %d", &width, &height );

    if( (width <= 0) || height <= 0 )
    {
        fprintf(stderr, "Podano zly wymiar planszy\n");
        return -1;
    }

    initState( &state1, width, height );
    initState( &state2, width, height );

    if( state1.board == NULL || state2.board == NULL )
    {
        fprintf(stderr, "Za malo pamieci!\n");
        return -1;
    }

    fileToState( &state1, in );
    sprintf( photoName, "photo0.png");
    writeStateToPNG(&state1, photoName);

    // glowna petla
    for( int i = 1; i <=  n; i++ )
    {
	sprintf( photoName, "photo%d.png", i );
        if( first == 1 )
        {
            next_round( &state1, &state2 );
            writeStateToPNG( &state2, photoName );
        }
        else
        {
            next_round( &state2, &state1 );
            writeStateToPNG( &state1, photoName );
        }
        first = !first;
    }

    if( argc > 3 )
    {
        if( first == 1 )
        {
            if( StateToFile( &state1, argv[3] ))
                fprintf(stderr, "Nie udalo sie otworzyc pliku do zapisu stanu\n");
        }
        else
        {
            if( StateToFile( &state2, argv[3] ))
                fprintf(stderr, "Nie udalo sie otworzyc pliku do zapisu stanu\n");
        }
    }

    freeState( &state1 );
    freeState( &state2 );
    return 0;
}
