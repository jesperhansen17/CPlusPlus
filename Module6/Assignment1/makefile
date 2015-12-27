CC = g++ -std=c++11
CFLAGS = -Wall -g
PROGRAM = Labb6

all: $(PROGRAM)

$(PROGRAM): main.o StructC.o
	$CC $^-o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $<

StructC.o: StructC.cpp
	$(CC) $(CFLAGS) $<	

run:
	./$(PROGRAM)

clean:
	rm *o $(PROGRAM) $<
