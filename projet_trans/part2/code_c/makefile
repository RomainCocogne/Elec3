# CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=-lsndfile -lm -lncurses 
EXEC=compile/visual_serie
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/visual_serie: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf ./*.o

compile/visual_serie.o: fft.h
compile/visual_serie.o: analyse_file.h
compile/visual_serie.o: mathematique.h
compile/visual_serie.o: plot.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf compile/*.o


mrproper: clean
	@rm -rf $(EXEC)
