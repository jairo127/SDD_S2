CFLAGS = -g -Wall -Wextra
OBJ = biblio.o main.o listes.o dates.o menu.o
EXEC = run

all: $(EXEC)

run : $(OBJ)
	gcc -o $(EXEC) $(OBJ)

biblio.o : Biblio/biblio.c Biblio/biblio.h
	gcc -o biblio.o -c Biblio/biblio.c $(CFLAGS)

listes.o : Listes/listes.c Listes/listes.h Biblio/biblio.h
	gcc -o listes.o -c Listes/listes.c $(CFLAGS)

dates.o : Dates/dates.c Dates/dates.h Biblio/biblio.h
	gcc -o dates.o -c Dates/dates.c $(CFLAGS)

menu.o : Menu/menu.c Menu/menu.h Dates/dates.h Listes/listes.h Biblio/biblio.h
	gcc -o menu.o -c Menu/menu.c $(CFLAGS)

main.o : main.c Biblio/biblio.h Listes/listes.h Dates/dates.h Menu/menu.h
	gcc -o main.o -c main.c $(CFLAGS)

clean : 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
