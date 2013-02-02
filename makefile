IDIR = include
CC = g++
CFLAGS = -std=c++11 -I$(IDIR)

ODIR = obj
LDIR = lib
SDIR = src
LIBS = 

_DEPS = gameTypes.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = start.o gameTypes.o Game.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

andrewsgame: $(OBJ)
	g++ -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
