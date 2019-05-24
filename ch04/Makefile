
SRC :=$(wildcard *.cpp ./src/*.cpp)
OBJ :=$(patsubst %.cpp, %.o,$(SRC))
BIN :=$(patsubst %.o, %, $(OBJ))

CXXFLAGS+=-std=c++11
LDLIBS+=-lstdc++

all: $(BIN)
BIN: $(OBJ)
OBJ: $(BUILD) $(SRC)
BUILD:
	if [ ! -d "build" ]; then mkdir build;fi
.PYTHON: clean cleanobj
clean: cleanobj
	-rm -f $(BIN)
cleanobj:
	-rm -f $(OBJ)
