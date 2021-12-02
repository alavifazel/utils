#ifndef BOUNCING_TEXT_H
#define BOUNCING_TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	float x, y;
} Point;

void clear(void);
void show(int x, int y, char* text);
void bouncingText(char* text);

#endif
