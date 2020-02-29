#include <stdbool.h>
#include <stdio.h>



typedef struct CellState
{
    bool isLiving;
} CellStateT;

typedef struct State
{
    CellStateT **board;
    int width;
    int height;
}StateT;

void initState(StateT* state,int width,int height);
void freeState(StateT* state);
void writeState(StateT* state ,FILE* out);
