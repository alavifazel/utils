#ifndef CONVERSION_H
#define CONVERSION_H

#include <string.h>
#include <math.h>
#include <stdio.h>

void
binary_to_hex(const char* input, size_t inputBufferSize,
	      char* res, size_t resultBufferSize);

void
hex_to_binary (const char* input, size_t inputBufferSize,
	       char* res, size_t resultBufferSize);

#endif
