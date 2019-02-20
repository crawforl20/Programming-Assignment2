CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: Sudoku_Checker run clean

sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o %0

run:
	./Sudoku_Checker

clean:
	rm Sudoku_Checker
