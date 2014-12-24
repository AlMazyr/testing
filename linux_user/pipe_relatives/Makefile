.PHONY : all clean

TARGET:=pipe_relatives
CXX:=gcc
CXX_FLAGS:=-c -MD -Wall
LD_FLAGS:=-o

SRC_LIST:=$(wildcard *.c)
OBJ_LIST:=$(patsubst %.c, %.o, $(SRC_LIST))

all : $(TARGET)

$(TARGET) : $(OBJ_LIST)
	$(CXX) $(LD_FLAGS) $@ $^

%.o : %.c
	$(CXX) $(CXX_FLAGS) $<

clean : 
	rm *.o *.d *~ $(TARGET)

include $(wildcard *.d)
