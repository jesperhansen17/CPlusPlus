CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)

all: DDList

DDList: main.o DDList.o
	$(CC) $^ -o $@
	
main.o: main.cpp
	$(CC) $(CFLAGS) $<
	
DDList.o: DDList.cpp
	$(CC) $(CFLAGS) $<
	
clean:
	rm *o DDList
