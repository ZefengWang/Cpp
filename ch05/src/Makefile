# Nakefile created by zefengwang
# test on centos 7 (x86_64)
# with gcc version 4.8.5

SRC :=$(wildcard *.cpp) $(wildcard *.cc) $(wildcard *.c)
OBJ :=$(patsubst %.cpp, %.o, $(wildcard *.cpp)) $(patsubst %.cc, %.o, $(wildcard *.cc)) $(patsubst %.c, %.o, $(wildcard *.c))
BIN :=$(patsubst %.o, %, $(OBJ))
CXXFLAGS+=-std=c++11
LDLIBS+=-lstdc++
all: $(BIN)
BIN: $(OBJ)
OBJ: $(SRC)
.PYTHON: clean cleanobj
clean: cleanobj;-rm -f $(BIN)
cleanobj: ;-rm -f $(OBJ)
