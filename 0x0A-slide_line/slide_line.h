#ifndef SLIDE_LEFT
#define SLIDE_LEFT 0
#endif

#ifndef SLIDE_RIGHT
#define SLIDE_RIGHT 1
#endif

#ifndef SLIDE_H
#define SLIDE_H

#include <stdio.h>
#include <stdlib.h>

void left(int *line, size_t size);
void right(int *line, size_t size);
void merge(int *line, size_t size, int direction);
int slide_line(int *line, size_t size, int direction);

#endif
