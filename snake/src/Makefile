CC=gcc
CFLAGS=-I -Wall -Werror -Wextra -pedantic -std=c99 -lncurses
OBJ =  main.o snake.o

%.o: %.c $(EPS)
	$(CC) -c -o $@ $< $(CFLAGS)

snake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	$(RM) count *.o *~ snake
