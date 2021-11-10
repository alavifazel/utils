#ifndef CODE_GEN_H
#define CODE_GEN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <regex.h>
#include <ctype.h>

const char* generateJavaGetterSetter(char const*);
const char* generateCBoilerplate();

#endif
