#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"
#include "printFile.h"
#include "rules.h"

void error( int error )
{
    if( error == 0 )
    {
        fprintf(stderr, "Nie udalo sie otworzyc pliku wejsciowego\n");
        return;
    }
    else if ( error == 1 )
    {
        fprintf(stderr, "Za malo pamieci!\n");
    }
}

int main( int argc, char **argv )
{
    //1 argument to ilosc iteracji
    //2 argument to plik
    int n = argc > 1 ? atoi( argv[1] ) : 5;
    FILE *in = argc > 2 ? fopen( argv[2], "r" ) : fopen( "data.txt", "r");
    StateT state1;
    StateT state2;
    int width;
    int height;
    bool first = 1; // czy pierwsza plansza

    if( in == NULL )
    {
        error( 0 );
        return -1;
    }

    fscanf( in, "%d %d", &width, &height );

    initState( &state1, width, height );
    initState( &state2, width, height );

    if( state1.board == NULL || state2.board == NULL )
    {
        error( 1 );
        return -1;
    }

    fileToState( &state1, in );
    writeState( &state1, stdout );

    for( int i = 0; i < n; i++ )
    {
        system("cls");
        if( first == 1 )
        {
            next_round( &state1, &state2 );
            writeState( &state2, stdout );
        }
        else
        {
            next_round( &state2, &state1 );
            writeState( &state1, stdout );
        }
        first = !first;
    }
    
    freeState( &state1 );
    freeState( &state2 );
    return 0;
}