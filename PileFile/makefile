CFLAGS = -g -Wall -Wextra -l cmocka
EXEC = tests

all: $(EXEC)

tests: tests_pile tests_file

tests_pile : Pile/pile.c Pile/pile.h Pile/tests_pile.c
	gcc Pile/*.c -o Pile/tests $(CFLAGS)

tests_file : File/file.c File/file.h File/tests_file.c
	gcc File/*.c -o File/tests $(CFLAGS)

run : File/file.c File/file.h Pile/pile.c Pile/pile.h main.c
	gcc Pile/pile.c File/file.c main.c -o run $(CFLAGS)

mrproper:
	rm */$(EXEC) && rm run