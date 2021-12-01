#ifndef BOUNCING_TEXT_H
#define BOUNCING_TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 20
#define WIDTH 70
#define FPS 40

typedef struct {
	float x, y;
} Point;

void clear(void);
void show(int x, int y, char* text);
void bouncingText(char* text);

#endif
