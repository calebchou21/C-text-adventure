CC = gcc

CFLAGS = -Wall -g

LD = gcc

LDFLAGS = -lncurses

mygame: main.o TextActions.o
	$(LD) $(LDFLAGS) -o mygame main.o TextActions.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

TextActions.o: TextActions.c
	$(CC) $(CFLAGS) -c -o TextActions.o TextActions.c

clean:
	rm -f *.o mygame
