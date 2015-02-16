.PHONY : all clean

TARGET:=second_max
CXX:=g++
CXX_FLAGS:=-c -MD -Wall -std=gnu++11
LD_FLAGS:=-o

SRC_LIST:=$(wildcard *.cpp)
OBJ_LIST:=$(patsubst %.cpp, %.o, $(SRC_LIST))

all : $(TARGET)

$(TARGET) : $(OBJ_LIST)
	$(CXX) $(LD_FLAGS) $@ $^ 

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) $<

clean : 
	rm *.o *.d *~ $(TARGET)

include $(wildcard *.d)
