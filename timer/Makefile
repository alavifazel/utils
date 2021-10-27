CC = gcc

CFLAGS  = -g -Wall

TARGET = timer

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET).out $(TARGET).c -lm
	./$(TARGET).out

clean:
	$(RM) $(TARGET)


