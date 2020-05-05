CFLAGS = -g -Wall -Wextra
OBJ = arbre.o main.o
EXEC = run

all:$(EXEC)

run:$(OBJ)
	gcc -o run $(OBJ)

arbre.o: arbre.c arbre.h
	gcc -o arbre.o -c arbre.c $(CFLAGS)

main.o: main.c arbre.h
	gcc -o main.o -c main.c $(CFLAGS)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)