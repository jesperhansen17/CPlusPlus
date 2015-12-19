CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
PROGRAM = Rational

all: Rational

Rational: main.o Rational.o
	$(CC) $^ -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $<

Rational.o: Rational.cpp
	$(CC) $(CFLAGS) $<

run:
	./$(PROGRAM)

clean:
	rm *o $(PROGRAM) $<
