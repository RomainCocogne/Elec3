CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=-lsndfile -lm
EXEC=compile/analyse_file
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/analyse_file: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

compile/analyse_file.o: fft.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
