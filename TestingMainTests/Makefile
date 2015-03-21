CPPUTEST_HOME = /usr/local
CC = gcc
CXX = g++
CFLAGS = -Wextra -Wall -Werror -g3 -O2
LIBS = -lCppUTest -lCppUTestExt

.PHONY: all clean

all: TestingMainWithNamespaceTests.exe \
     TestingMainWithDefineTests.exe

%.o: %.c
	$(CC) -c $(CLAGS) $< -o $@

%.o: %.cpp
	$(CXX) -c $(CFLAGS) -I$(CPPUTEST_HOME)/include $< -o $@

TestingMainWithNamespaceTests.exe: Control_class_wrapper.o \
    TestingMainWithNamespaceTests.o RunAllTests.o
	$(CXX) $(CFLAGS) -L$(CPPUTEST_HOME)/lib $? $(LIBS) -o $@
	./$@ -v

TestingMainWithDefineTests.exe: Control_class_wrapper_c.o \
    TestingMainWithDefineTests.o RunAllTests.o
	$(CXX) $(CFLAGS) -L$(CPPUTEST_HOME)/lib $? $(LIBS) -o $@
	./$@ -v

Control_class_wrapper.o Control_class_wrapper_c.o \
    TestingMainWithNamespaceTests.o \
    TestingMainWithDefineTests.o RunAllTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYM
