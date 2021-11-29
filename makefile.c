#include <string.h>

char* CMakefile(char *fileNames) {
  static char content[1024];
  const char* compiler = "CC = gcc\n";
  const char* flags = "CFLAGS = -g -Wall";
  
  strcat(content, compiler);
  strcat(content, flags);
  strcat(content, "TARGET = target\n\n");
  strcat(content, "all:\n");
  strcat(content, "\t$(TARGET)\n\n");
  strcat(content, "$(TARGET): $(TARGET).c\n");
  strcat(content, "$(CC) $(CFLAGS) -o $(OUTPUT) $(TARGET).c");
  strcat(content, fileNames);
  strcat(content, "\n\nclean:\n");
  strcat(content, "\t$(RM) $(TARGET)");

  return content;
}
