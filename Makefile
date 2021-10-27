CC = gcc

CFLAGS  = -g -Wall

TARGET = timer

all:
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$(TARGET).out $(TARGET)/$(TARGET).c -lm

clean:
	rm -r build/


