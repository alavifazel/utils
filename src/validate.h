#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

enum CommandEnum {
		TIMER,
		GETTER_SETTER_GEN,
		BOILERPLATE_GEN,
		MAKEFILE,
		BOUNCING_TEXT,
		BIN_TO_HEX,
		HEX_TO_BIN
};

enum lang { JAVA, C };

struct Command {
	char* str;
	enum CommandEnum cmd;
};

struct Command *getCommands();
const char **getLanguagesList();
bool validateInput(int argv, const char *argc[]);

#endif
