#include "validate.h"

struct Command *getCommands() {
  static struct Command cmds[NUM_OF_COMMANDS];
  cmds[0].str = "gs";
  cmds[0].cmd = GETTER_SETTER_GEN;

  cmds[1].str = "bp";
  cmds[1].cmd = BOILERPLATE_GEN;

  cmds[1].str = "bp";
  cmds[1].cmd = BOILERPLATE_GEN;

  cmds[2].str = "timer";
  cmds[2].cmd = TIMER;

  return cmds;
}

const char **getLanguagesList() {
  static const char* list[] = {"java", "c"};
  return list;
}

bool oneWordCommand(const char **input) {
  struct Command *cmds = getCommands();
  for(size_t i = 0; i < NUM_OF_COMMANDS; ++i) {
	  if(cmds[i].cmd == TIMER)
		if(strcmp(cmds[i].str, input[1]) == 0) return true;
  }
  return false;
}

bool twoWordCommand(const char **input) {
  const size_t numOfValidationParameters = 2;
  bool *validationParameters = malloc(sizeof(bool) * numOfValidationParameters);
  for(size_t i = 0; i < numOfValidationParameters; ++i) {
	validationParameters[i] = false;
  }

  const char **list = getLanguagesList();
  while(*list) {
    if(strcmp(input[1], *list) == 0) validationParameters[0] = true;
    list++;
  }
  struct Command *cmds = getCommands();
  for(size_t i = 0; i < NUM_OF_COMMANDS; ++i) {
	  if(cmds[i].cmd == GETTER_SETTER_GEN || 
	     cmds[i].cmd == BOILERPLATE_GEN)
		  if(strcmp(cmds[i].str, input[2]) == 0)
			  validationParameters[1] = true;
  }

  bool result = true;
  for(size_t i = 0; i < numOfValidationParameters; ++i)
	  result = result && validationParameters[i];
  free(validationParameters);
  return result;

}

bool validateInput(int argv, const char *argc[]) {
  if(argv < 2) return false;
  if(oneWordCommand(argc)) return true; 
  if(twoWordCommand(argc)) return true;
  return false;
}
