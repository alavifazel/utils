/* Generates getter/setters for different languages (currently Java)
 Example usage:
 
   ./x java private int myField\;

 Output:

   public int getMyField() { 
       return this.myField;
   }
  
   public void setMyField(int myField) { 
       this.myField = myField;
   }

 */

#include "timer.h"
#include "validate.h"
#include "code_gen.h"
#include "macros.h"
#include "makefile.h"
#include "bouncing_text.h"

bool stringNotContain(const char *, const char *);

int main(int argv, const char *argc[]){
  if(!validateInput(argv, argc)) {
    printf("%s", USAGE);
    exit(1);
  }

  size_t s = 0;
  char* str;
  for(size_t i = 2; i < argv; ++i) s += strlen(argc[i]);
  str = malloc(s + argv);
  for(size_t i = 2; i < argv; ++i) { 
    strcat(str, argc[i]);
    if(i < argv - 1) strcat(str, " ");
  }
  
  if(strcmp(argc[1], "timer") == 0) {
    loopTimePrint();
  }

  if(strcmp(argc[1], "bouncing") == 0) {
	  char text[256];
	  for(int i = 2; i < argv; ++i) {
		  strcat(text, argc[i]);
		  strcat(text, " ");
	  }
	  bouncingText(text);
  }

  if(strcmp(argc[1], "java") == 0) {
    if(strcmp(argc[2], "gs") == 0) { 
      printf("%s", generateJavaGetterSetter(str));
    }
  }

  if(strcmp(argc[1], "c") == 0) {
    if(strcmp(argc[2], "makefile") == 0) {
      char fileNames[128]; // TODO: Make the size to the precise number
      for(size_t i = 3; i < argv; ++i) {
    	  strcat(fileNames, argc[i]);
    	  strcat(fileNames, ".c ");
      }
      printf("%s", CMakefile(fileNames));
    }
   if(strcmp(argc[2], "bp") == 0) {

     if(argv <= 3) {
         printf("%s", generateCBoilerplate());
     } else if(strcmp(argc[3], "-") == 0) {
        printf("15");
     }
   }
  }

  if(strcmp(argc[1], "html") == 0) { // Mimics Emmet commands
   if(strcmp(argc[2], "bp") == 0) {
     if(argv <= 3) {
       printf("%s", generateHTMLBoilerplate());
     } else if(strcmp(argc[3], "-") == 0) {
       printf("15");
     } else {
	if(stringNotContain(argc[3], ".")) {
           printf("15");
        } else {

           printf("5");
        }
      } 
    }
  }

  free(str);
}

bool stringNotContain(const char *str, const char *chars) {
  for(size_t i = 0; i < strlen(str); ++i) {
    for(size_t j = 0; j < strlen(chars); j++) {
      if(str[i] == chars[j]) return false;
    }
  }
  return true;
}
