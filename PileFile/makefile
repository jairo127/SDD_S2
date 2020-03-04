CFLAGS = -g -Wall -Wextra -l cmocka
EXEC = tests

all: $(EXEC)

tests: tests_pile tests_file

tests_pile : Pile/pile.c Pile/pile.h Pile/tests_pile.c
	gcc Pile/*.c -o Pile/tests $(CFLAGS)

tests_file : File/file.c File/file.h File/tests_file.c
	gcc File/*.c -o File/tests $(CFLAGS)

mrproper:
	rm */$(EXEC)