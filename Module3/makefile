CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
PROGRAM = StringIterator

all: StringIterator

StringIterator: main.o String.o Iterator.o
	$(CC) $^ -o $@
	
main.o: main.cpp
	$(CC) $(CFLAGS) $<
	
String.o: String.cpp
	$(CC) $(CFLAGS) $<

Iterator.o: Iterator.cpp
	$(CC) $(CFLAGS) $<

run:
	./$(PROGRAM)
	
clean:
	rm *o $(PROGRAM) $<
