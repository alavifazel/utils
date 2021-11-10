#ifndef TIMER_H
#define TIMER_H

#ifndef _WIN32
#include <unistd.h>
#else
#include <windows.h>
#endif
#include <stdio.h>
#include <time.h>
#include <math.h>

const char* getCurrentTime();
void loopTimePrint();

#endif
