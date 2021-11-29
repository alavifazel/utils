#include "code_gen.h"
#include "macros.h"

const char* generateJavaGetterSetter(char const* str) {
  static char buffer[1024]= "";
  char type[128];
  char name[128];
  size_t maxGroup = 4;
  regex_t regex;
  const char* regexString = "(:?private)*([[:space:]]*.*[^[:space:]])[[:space:]]*([[:space:]].*);$";
  regmatch_t regexGroups[maxGroup];
  if(regcomp(&regex, regexString, REG_EXTENDED)) {
    fprintf(stderr, "ERR!");
    exit(1);
  }

  const char* cursor = str;
  if(!regexec(&regex, cursor, maxGroup, regexGroups, 0)) {

    for(size_t g = 1; g < maxGroup; ++g) {
      if(regexGroups[g].rm_so == -1) break;

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

  strcat(buffer, "private ");
  strcat(buffer, type);
  strcat(buffer, " ");
  strcat(buffer, name);
  strcat(buffer, ";\n");

  strcat(buffer, getter);
  strcat(buffer, setter);

  return buffer;
}

const char* generateCBoilerplate() {
  return C_BOILERPLATE;
}

const char* generateHTMLBoilerplate() {
  return HTML_BOILERPLATE;
}
