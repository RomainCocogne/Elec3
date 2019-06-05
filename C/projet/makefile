CC=gcc
CFLAGS=-Wall -pedantic -g3
LDFLAGS= -lm -lsx
EXEC=compile/main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf ./*.o

compile/main.o: jeu.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf compile/*.o


mrproper: clean
	@rm -rf $(EXEC)
