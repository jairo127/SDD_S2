CFLAGS = -g -Wall -Wextra
OBJ = table.o main.o
EXEC = run

all: $(EXEC)

run: $(OBJ)
	gcc -o $(EXEC) $(OBJ)

table.o : table.c table.h
	gcc -o table.o -c table.c $(CFLAGS)

main.o : main.c table.h
	gcc -o main.o -c main.c $(CFLAGS)

clear:
	rm -f $(OBJ)

mrproper: clear
	rm -f $(EXEC)
