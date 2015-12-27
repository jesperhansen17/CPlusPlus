CC = g++ -std=c++11
CFLAGS = -Wall -g

DEPS = Rational.h

ODIR = obj

_OBJ = main.o Rational.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


PROGRAM = Rational

all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CC) $^ -o $@

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/:
	mkdir -p $@

run:
	./$(PROGRAM)

clean:
	rm $(ODIR)/*o $(PROGRAM) $<
