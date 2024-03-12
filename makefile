TARGET = arabica.exe

CC = gcc
CFLAGS = -Werror -Wall -Wextra
LIBS = -lncurses
MAIN = ./main.c
SRCS = $(MAIN)
OBJS = $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)