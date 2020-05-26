CFLAGS = -g -Wall -Wextra
OBJ = arbre.o pile.o file.o main.o
EXEC = run

all: $(EXEC)

run : $(OBJ)
	        gcc -o $(EXEC) $(OBJ)

arbre.o : arbre.c arbre.h type_arbre.h
	gcc -o arbre.o -c arbre.c $(CFLAGS)

pile.o : pile.c pile.h type_arbre.h
	gcc -o pile.o -c pile.c $(CFLAGS)

file.o : file.c file.h type_arbre.h
	gcc -o file.o -c file.c $(CFLAGS)

main.o : main.c arbre.h pile.h file.h type_arbre.h
	gcc -o main.o -c main.c $(CFLAGS)
	
clean :
	        rm -f $(OBJ)

mrproper: clean
	        rm -f $(EXEC)
