CC = gcc

CFLAGS = -Wall -g

LD = gcc

LDFLAGS = 

mygame: main.o text_actions.o
	$(LD) $(LDFLAGS) -o mygame main.o text_actions.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

text_actions.o: text_actions.c
	$(CC) $(CFLAGS) -c -o text_actions.o text_actions.c


