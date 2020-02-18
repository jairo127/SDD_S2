CFLAGS = -g -Wall -Wextra
OBJ = biblio.o main.o listes.o dates.o menu.o
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

menu.o : menu.c menu.h dates.h listes.h biblio.h
	gcc -o menu.o -c menu.c $(CFLAGS)

main.o : main.c biblio.h listes.h dates.h menu.h
	gcc -o main.o -c main.c $(CFLAGS)

clean : 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
