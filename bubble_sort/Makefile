.PHONY : all clean

TARGET:=bubble_sort
CXX:=gcc
CXX_FLAGS:=-c -MD -Wall
LD_FLAGS:=-o

SRC_LIST:=$(wildcard *.c)
OBJ_LIST:=$(patsubst %.c, %.o, $(SRC_LIST))

all : $(TARGET)

$(TARGET) : $(OBJ_LIST)
	$(CXX) $(LD_FLAGS) $@ $^

%.o : %.cpp
	$(CXX) $(CXX_FLAGS) $<

clean : 
	rm *.o *.d *~ $(TARGET)

include $(wildcard *.d)
