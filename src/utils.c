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
#include "conversions.h"

bool stringNotContain(const char *, const char *);

int main(int argc, const char *argv[]){
  if(!validateInput(argc, argv)) {
    printf("%s", USAGE);
    exit(1);
  }

  size_t s = 0;
  char* str;
  for(size_t i = 3; i < argc; ++i) s += strlen(argv[i]);
  str = malloc(s + argc);
  for(size_t i = 3; i < argc; ++i) { 
    strcat(str, argv[i]);
    if(i < argc - 1) strcat(str, " ");
  }

 if(strcmp(argv[1], "timer") == 0) {
    loopTimePrint();
  }

 if(strcmp(argv[1], "bouncing") == 0) {
   char text[256];
   for(int i = 2; i < argc; ++i) {
     strcat(text, argv[i]);
     strcat(text, " ");
   }
   bouncingText(text);
 }

  if(strcmp(argv[1], "bin2hex") == 0) { 
    size_t input_size = strlen(argv[2] + 1);
    size_t res_size =  input_size / 4;
    char output[res_size];
    binary_to_hex(argv[2], input_size, output, res_size);
    printf("%s\n", output);
  }
  
  if(strcmp(argv[1], "hex2bin") == 0) { 
    size_t input_size = strlen(argv[2] + 1);
    size_t res_size =  input_size * 4;
    char output[res_size];
    hex_to_binary(argv[2], input_size, output, res_size);
    printf("%s\n", output);
  }

  if(strcmp(argv[1], "java") == 0) {
    if(strcmp(argv[2], "gs") == 0) { 
      printf("%s", generateJavaGetterSetter(str));
    }
  }

  if(strcmp(argv[1], "c") == 0) {
    if(strcmp(argv[2], "makefile") == 0) {
      char fileNames[128]; // TODO: Make the size to the precise number
      for(size_t i = 3; i < argc; ++i) {
    	  strcat(fileNames, argv[i]);
    	  strcat(fileNames, ".c ");
      }
      printf("%s", CMakefile(fileNames));
    }
   if(strcmp(argv[2], "bp") == 0) {

     if(argc <= 3) {
         printf("%s", generateCBoilerplate());
     } else if(strcmp(argv[3], "-") == 0) {
        printf("15");
     }
   }
  }

  if(strcmp(argv[1], "html") == 0) { // Mimics Emmet commands
    if(strcmp(argv[2], "bp") == 0) {
      if(argc <= 3) {
	printf("%s", generateHTMLBoilerplate());
      } else if(strcmp(argv[3], "-") == 0) {
	printf("15");
      } else {
	if(stringNotContain(argv[3], ".")) {
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
