#ifndef RULES_H
#define RULES_H

#include <stdbool.h>
#include <stdio.h>
#include "map.h"
#include "neighborhood.h"

//mowi czy urodzic czy zabic komorke
bool born_kill( StateT* state, int x, int y);

//przechodzi do nastepnej tury, na podstawie state1 robi state2
void next_round( StateT* state1, StateT* state2);

#endif