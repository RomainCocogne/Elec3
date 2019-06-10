CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS= -lm -lsx
EXEC=main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf ./*.o

main.o: score.h
main.o: callbacks.h
main.o: display.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o


mrproper: clean
	@rm -rf $(EXEC)

