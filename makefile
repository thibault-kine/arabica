TARGET = arabica.exe

CC = gcc
CFLAGS = -Werror -Wall -Wextra
MAIN = ./src/main.c
SRCS = $(MAIN) ./src/token_analysis.c ./src/token_struct.c
OBJS = $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

run: all
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)