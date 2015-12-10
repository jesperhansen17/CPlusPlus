CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)

all: String

String: main.o String.o
	$(CC) $^ -o $@
	
main.o: main.cpp
	$(CC) $(CFLAGS) $<
	
String.o: String.cpp
	$(CC) $(CFLAGS) $<
	
clean:
	rm *o String
