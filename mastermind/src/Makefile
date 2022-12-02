CC=gcc
CFLAGS=-I -Wall -Werror -Wextra -pedantic -std=c99
OBJ =  main.o  color.o mastermind.o

%.o: %.c $(EPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mastermind: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	$(RM) count *.o *~ mastermind
