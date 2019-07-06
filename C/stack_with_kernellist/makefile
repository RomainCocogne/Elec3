CC=gcc
CFLAGS=-Wall 
LDFLAGS=-lsx -g3
EXEC=compile/main
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/main: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf *.o

compile/main.o: stack.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
