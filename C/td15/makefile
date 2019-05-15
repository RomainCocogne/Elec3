CC=gcc
CFLAGS=-Wall -pedantic 
LDFLAGS=-lsx
EXEC=compile/conv
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/conv: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf *.o

compile/conv.o: callbacks.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
