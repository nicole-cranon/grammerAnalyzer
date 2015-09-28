# nicole cranon <nicole.cranon@ucdenver.edu>
# csci 4640, fall 2015
# assignment 5 - grammer analyzer
# makefile

CC=g++ -std=c++11
CFLAGS=-c -Wall -g
INC=-I ./include

analyze: main.o grammerAnalyzer.o 
	$(CC) main.o grammerAnalyzer.o -o analyze

main.o: ./src/main.cpp
	$(CC) $(INC) $(CFLAGS) ./src/main.cpp -o main.o

grammerAnalyzer.o: ./src/grammerAnalyzer.cpp
	$(CC) $(INC) $(CFLAGS) ./src/grammerAnalyzer.cpp -o grammerAnalyzer.o

clean:
	rm *.o -f; rm analyze -f
