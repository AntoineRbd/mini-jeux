CC=gcc
CFLAGS=-I -Wall -Werror -Wextra -pedantic -std=c99
OBJ =  main.c color.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mastermind: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	$(RM) count *.o *~ mastermind
