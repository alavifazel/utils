CC = gcc

CFLAGS  = -g -Wall

TARGET = utils
OUTPUT = x

all: $(TARGET) 

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(OUTPUT) $(TARGET).c validate.c timer.c code_gen.c makefile.c bouncing_text.c -lm

clean:
	$(RM) $(TARGET)

install:
	sudo mv x /usr/bin/local


