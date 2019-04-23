
CC=gcc
CXXFLAGS=
LDFLAGS=
LDLIBS+=-lstdc++

BIN+=ex01
BIN+=ex02
BIN+=ex03
BIN+=ex04
BIN+=ex05
BIN+=ex06
#SRC=$(BIN).cc
#OBJ=$(BIN).o

all: $(BIN)
#BIN: $(OBJ)
#	$(CC) $(OBJ) $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $(BIN)

#OBJ: $(SRC)
#	$(CC) -c $(SRC) -o $(OBJ)

.PHONY: clean
clean:
	-rm -rf $(BIN) $(OBJ)

