CC = gcc

CFLAGS  = -g -Wall

TARGET = utils
OUTPUT = x

all: $(TARGET) 

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(OUTPUT) $(TARGET).c validate.c timer.c code_gen.c -lm

clean:
	$(RM) $(TARGET)


