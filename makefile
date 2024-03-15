TARGET = arabica

CC = gcc
CFLAGS = -Werror -Wall -Wextra -I include -g3
VAL = valgrind --leak-check=yes --tool=memcheck --log-file=.log --vgdb=yes
MAIN = src/main.c
SRCS = $(MAIN) src/token_analysis.c src/token_struct.c src/read_arabica.c src/utils.c
OBJS = $(SRCS:%.c=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS)

run: all
	$(VAL) ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)