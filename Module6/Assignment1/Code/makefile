CC = g++ -std=c++11
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
PROGRAM = Algoritmer

all: $(PROGRAM)

$(PROGRAM): main.o String.o Iterator.o HiResTimer.o
	$(CC) $^ -o $@
	
main.o: main.cpp
	$(CC) $(CFLAGS) $<
	
String.o: String.cpp
	$(CC) $(CFLAGS) $<

Iterator.o: Iterator.cpp
	$(CC) $(CFLAGS) $<

HiResTimer.o: HiResTimer.cpp
	$(CC) $(CFLAGS) $<

run:
	./$(PROGRAM)
	
clean:
	rm *o $(PROGRAM) $<
