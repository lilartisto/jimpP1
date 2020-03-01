#include "neighborhood.h"
#include <stdio.h>

int count_neighborhood(StateT *state, int x , int y)
{
    int counter = 0;
    if(state->board[y][x] == 1);
        counter--; //jesli podany punkt ma wartosc 1 to odejmujemy jednego "sasiada"(podany punkt) 
    
    int moore = 3;
    for (int i = 0; i < moore; i++)
        for (int j = 0; j < moore; j++)
        {
            if (state->board[y - 1 + i][x - 1 + j] == 1)
                counter++;
        }
    return counter;
}