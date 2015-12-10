CC = g++
DEBUG = -g
CFLAGS = -c -Wall $(DEBUG)
PROGRAM = Shared_Ptr

all: Shared_Ptr

Shared_Ptr: main.o Shared_Ptr.o
	$(CC) $^ -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) $<

Shared_Ptr.o: Shared_Ptr.cpp
	$(CC) $(CFLAGS) $<

run:
	./$(PROGRAM)

clean:
	rm *o $(PROGRAM) $<
