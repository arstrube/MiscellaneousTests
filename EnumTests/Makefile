LIBS = -lCppUTest -lCppUTestExt 
CXX = g++
CC = gcc
CFLAGS = -L/usr/local/lib -Wextra -Wall -Werror -g
CXXFLAGS = $(CFLAGS) -std=c++11

.PHONY: all clean

all: EnumTests.exe

EnumTests.exe: EnumTests.o CppColorsTests.o Colors_real.o Colors_fake.o LedState_fake.o
	$(CXX) $(CFLAGS) $? $(LIBS) -o $@
	./$@ -v
    
%.o: Makefile

clean:
	rm -f *.o *.exe;
