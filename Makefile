sudoku: main.o sudoku.o
	g++ main.o sudoku.o -o sudoku

main.o: main.cpp sudoku.h
	g++ -Wall -g -c main.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -Wall -g -c sudoku.cpp

.PHONY: clean
clean:
	rm -f main.o sudoku.o sudoku
