CXX = g++
CC  = gcc
AR = ar
CXXFLAGS = -g3 -Wextra -Wall -Werror -O0 -I/usr/local/include
CFLAGS = -std=c99 $(CXXFLAGS)
LIBS= -lCppUTest -lCppUTestExt
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean i

all: i ArrayTypesTests.exe

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
ArrayTypesTests.exe: ArrayTypesTests.o ArrayTypes.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v -c

ArrayTypesTests.o ArrayTypes.o: Makefile

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
