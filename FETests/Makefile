LIBS = -lCppUTest -lCppUTestExt 
CXX = g++
CC = gcc
CFLAGS = -L/usr/local/lib -Wextra -Wall -Werror -g \
         -frounding-math

CXXFLAGS = $(CFLAGS) -std=c++11

.PHONY: all clean

all: FETests.exe

FETests.exe: FETests.o FETests_c.o
	$(CXX) $(CFLAGS) $? $(LIBS) -o $@
	./$@ -v
    
FETests.o FETests_c.o: Makefile

clean:
	rm -f *.o *.exe;