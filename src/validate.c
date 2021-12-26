#include "validate.h"

#define NUM_OF_COMMANDS 7

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

  cmds[3].str = "makefile";
  cmds[3].cmd = MAKEFILE;

  cmds[4].str = "bouncing";
  cmds[4].cmd = BOUNCING_TEXT;

  cmds[5].str = "bin2hex";
  cmds[5].cmd = BIN_TO_HEX;

  cmds[6].str = "hex2bin";
  cmds[6].cmd = HEX_TO_BIN;

  return cmds;
}

const char **getLanguagesList() {
  static const char* list[] = {"java", "c", "html"};
  return list;
}

bool oneWordCommand(const char **input, int numOfInputs) {

  struct Command *cmds = getCommands();
  for(size_t i = 0; i < NUM_OF_COMMANDS; ++i) {
    if(cmds[i].cmd == TIMER ||
       cmds[i].cmd == BOUNCING_TEXT ||
       cmds[i].cmd == HEX_TO_BIN ||
       cmds[i].cmd == BIN_TO_HEX)
      if(strcmp(cmds[i].str, input[1]) == 0) return true;
  }
  return false;
}

bool twoWordCommand(const char **input, int numOfInputs) {
  if(numOfInputs <= 2) return false;
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
    // Still don't like this approach,
    // but does the job.
    if(cmds[i].cmd == GETTER_SETTER_GEN || 
       cmds[i].cmd == BOILERPLATE_GEN ||
       cmds[i].cmd == MAKEFILE)
      if(strcmp(cmds[i].str, input[2]) == 0)
	validationParameters[1] = true;
  }

  bool result = true;
  for(size_t i = 0; i < numOfValidationParameters; ++i)
    result = result && validationParameters[i];
  free(validationParameters);
  return result;
}

bool validateInput(int argc, const char *argv[]) {
  if(argc < 2) return false;
  if(oneWordCommand(argv, argc)) return true;
  if(twoWordCommand(argv, argc)) return true;
  return false;
}
