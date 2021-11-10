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

int main(int argv, const char *argc[]){
  if(!validateInput(argv, argc)) {
    fprintf(stderr, "ERR!");
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

  if(strcmp(argc[1], "timer") == 0)
	  loopTimePrint();
  if(strcmp(argc[1], "java") == 0)
    if(strcmp(argc[2], "gs") == 0) 
      printf("%s", generateJavaGetterSetter(str));

  if(strcmp(argc[1], "c") == 0)
   if(strcmp(argc[2], "bp") == 0) 
     printf("%s", generateCBoilerplate());

  free(str);
}

