CFLAGS =  -g3 -O0 -Wextra -Wall -Werror \
          -include"CppuTest/MemoryLeakDetectorMallocMacros.h" 
CXXFLAGS = $(CFLAGS) \
          -include"CppuTest/MemoryLeakDetectorNewMacros.h"
.PHONY: all clean
LIBS=-lCppUTest
LIB_PATH=-L. -L/usr/local/lib

all: MemLeakDetectTests.exe

MemLeakDetectTests.exe: uses_malloc.o MemLeakDetectTests.o
	$(CXX) $(CXXFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	./$@

uses_malloc.o MemLeakDetectTests.o : Makefile uses_malloc.h

clean:
	rm -rf *.exe *.o *.dSYM *.stackdump
