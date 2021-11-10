#include "code_gen.h"

const char* generateJavaGetterSetter(char const* str) {
  static char buffer[1024]= "";
  char type[128];
  char name[128];
  size_t maxGroup = 4;
  regex_t regex;
  const char* regexString = ".*([[:space:]].*[^[:space:]])[[:space:]]*([[:space:]].*);$";
  regmatch_t regexGroups[maxGroup];
  if(regcomp(&regex, regexString, REG_EXTENDED)) {
    fprintf(stderr, "ERR!");
    exit(1);
  }

  const char* cursor = str;
  if(!regexec(&regex, cursor, maxGroup, regexGroups, 0)) {
    size_t offset = 0;

    for(size_t g = 1; g < maxGroup; ++g) {
      if(regexGroups[g].rm_so == -1) break;
      if(g == 0) 
	offset = regexGroups[g].rm_eo;

      char cursorCopy[strlen(cursor) + 1];
      strcpy(cursorCopy, cursor);
      cursorCopy[regexGroups[g].rm_eo] = 0;
      if(g == 1) strcpy(type, cursorCopy + regexGroups[g].rm_so + 1);
      if(g == 2) strcpy(name, cursorCopy + regexGroups[g].rm_so + 1);
     }

  }

  char uppercaseName[128];
  char getter[1024];
  char setter[1024];
  
  strncpy(uppercaseName, name, sizeof(name));
  uppercaseName[0] = toupper(uppercaseName[0]);
  strcat(setter, name);
  buffer[strlen(setter) - strlen(name)] = toupper(name[0]);
  snprintf(setter, sizeof(setter),
	   "\npublic void set%s"
	   "(%s %s) { \n\t this.%s = %s;\n"
	   "}\n",
	   uppercaseName, type, name, name, name);
  
  snprintf(getter, sizeof(getter),
	   "\npublic %s get%s() { \n"
	   "\t return this.%s;\n"
	   "}\n",
	   type, uppercaseName, name);

  strcat(buffer, getter);
  strcat(buffer, setter);

  return buffer;
}

const char* generateCBoilerplate() {
  static char code[128];
  snprintf(code, sizeof(code),
		  "#include <stdio.h>\n"
		  "\n"
		  "int main(int argv, char** argc) {\n"
		  "    return 0\n"
		  "}\n");
  return code;
}
