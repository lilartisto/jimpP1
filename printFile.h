#ifndef PRINTFILE_H
#define PRINTFILE_H

#include <stdio.h>
#include <png.h>
#include "map.h"

void writeState(StateT* state ,FILE* out);
void writeStateToPBM(StateT* state , int i);

int x, y;

int width, height;
png_byte color_type;
png_byte bit_depth;

png_structp png_ptr;
png_infop info_ptr;
int number_of_passes;
png_bytep * row_pointers;

void write_png_file(char* file_name);
void process_file( StateT *state );

#endif