CFLAGS = -g -Wall -Wextra
OBJ = biblio.o main.o listes.o dates.o
EXEC = run

all: $(EXEC)

run : $(OBJ)
	gcc -o $(EXEC) $(OBJ)

biblio.o : biblio.c biblio.h
	gcc -o biblio.o -c biblio.c $(CFLAGS)

listes.o : listes.c listes.h biblio.h
	gcc -o listes.o -c listes.c $(CFLAGS)

dates.o : dates.c dates.h biblio.h
	gcc -o dates.o -c dates.c $(CFLAGS)

main.o : main.c biblio.h listes.h dates.h
	gcc -o main.o -c main.c $(CFLAGS)

clean : 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
