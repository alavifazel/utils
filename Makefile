CC = gcc

CFLAGS  = -g -Wall

SRC_DIR = src
SRC := $(wildcard $(SRC_DIR)/*.c)
TARGET = utils
OUTPUT = x

all: $(SRC_DIR)/$(TARGET) 

$(SRC_DIR)/$(TARGET): $(SRC_DIR)/$(TARGET).c
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC) -lm

clean:
	$(RM) $(TARGET)

install:
	sudo mv x /usr/bin/local
