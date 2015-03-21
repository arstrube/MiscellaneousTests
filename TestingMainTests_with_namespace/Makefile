CPPUTEST_HOME = /usr/local
CC = gcc
CXX = g++
CFLAGS = -Wextra -Wall -Werror -O2
LIBS = -lCppUTest -lCppUTestExt

.PHONY: all clean

all: TestingMainWithNamespaceTests.exe \
     TestingMainWithDefineTests.exe

%.o: %.c
	$(CC) -c $(CLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(CFLAGS) -I$(CPPUTEST_HOME)/include $< -o $@

TestingMainWithNamespaceTests.exe: Control_class_wrapper.o \
    TestingMainWithNamespaceTests.o AllTests.o
	$(CXX) $(CFLAGS) -L$(CPPUTEST_HOME)/lib $? $(LIBS) -o $@
	./$@

TestingMainWithDefineTests.exe: Control_class_wrapper_c.o \
    TestingMainWithDefineTests.o AllTests.o
	$(CXX) $(CFLAGS) -L$(CPPUTEST_HOME)/lib $? $(LIBS) -o $@
	./$@

Control_class_wrapper.o Control_class_wrapper_c.o \
    TestingMainWithNamespaceTests.o \
    TestingMainWithDefineTests.o AllTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYM
