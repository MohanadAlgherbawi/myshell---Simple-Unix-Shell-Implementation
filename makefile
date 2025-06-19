CC = gcc
CFLAGS = -Wall -Wextra
TARGET = myshell
SRC = myshell.c utility.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c myshell.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)

.PHONY: all clean
