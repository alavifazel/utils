#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define NUM_OF_COMMANDS 3

enum CommandEnum { TIMER,
	           GETTER_SETTER_GEN, 
		   BOILERPLATE_GEN};

enum lang { JAVA, CPP };

struct Command {
	char* str;
	enum CommandEnum cmd;
};

struct Command *getCommands();
const char **getLanguagesList();
bool validateInput(int argv, const char *argc[]);

#endif
