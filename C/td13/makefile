CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=
EXEC=compile/cal
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/cal: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

compile/cal.o: pile.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
