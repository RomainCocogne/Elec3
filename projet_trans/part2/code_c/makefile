CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=-lsndfile -lm -lncurses 
EXEC=compile/visual_sound
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC)

compile/visual_sound: $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)
	@rm -rf ./*.o

compile/visual_sound.o: fft.h
compile/visual_sound.o: analyse_file.h
compile/visual_sound.o: mathematique.h
compile/visual_sound.o: plot.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf compile/*.o


mrproper: clean
	@rm -rf $(EXEC)
