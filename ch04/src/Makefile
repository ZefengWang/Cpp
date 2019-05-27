# Nakefile created by zefengwang
# test on centos 7 (x86_64)
# with gcc version 4.8.5

SRC :=$(wildcard *.cpp ./*.cpp) $(wildcard *.cc ./*.cc)
OBJ :=$(patsubst %.cpp, %.o,$(wildcard *.cpp ./*.cpp)) $(patsubst %.cc, %.o,$(wildcard *.cc ./*.cc))
BIN :=$(patsubst %.o, %, $(OBJ))
CXXFLAGS+=-std=c++11
LDLIBS+=-lstdc++
all: $(BIN)
BIN: $(OBJ)
OBJ: $(SRC)
.PYTHON: clean cleanobj
clean: cleanobj;-rm -f $(BIN)
cleanobj: ;-rm -f $(OBJ)
