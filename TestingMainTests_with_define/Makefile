CPPUTEST_HOME = /usr/local
CC = gcc
CXX = g++
CFLAGS =  -Wextra -Wall -Werror -O2
CXXFLAGS = -Wextra -Wall -Werror -O2
LIBS = -lCppUTest -lCppUTestExt

.PHONY: all clean

all: TestingMainTests.exe

%.o: %.c
	$(CC) -c $(CLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -I$(CPPUTEST_HOME)/include $< -o $@

TestingMainTests.exe: Control_class_wrapper.o TestingMainTests.o AllTests.o
	$(CXX) $(CXXFLAGS) -L$(CPPUTEST_HOME)/lib $(LIBS) $? -o $@
	./$@

Control_class_wrapper.o TestingMainTests.o AllTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYMcd
