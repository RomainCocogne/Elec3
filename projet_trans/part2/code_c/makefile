CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=-lsndfile -lm
EXEC=compile/analyse_file
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/analyse_file: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf ./*.o

compile/analyse_file.o: fft.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf compile/*.o


mrproper: clean
	@rm -rf $(EXEC)
