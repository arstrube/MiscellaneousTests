CFLAGS = \
  -g3 -O0 -Wextra -Wall -Werror \
  -include"CppuTest/MemoryLeakDetectorMallocMacros.h" \
  -I/usr/local/include \
# -I/cygdrive/y/ModuleTest/90_Tools/CppUTestFramework/CppUTest/include \

CXXFLAGS = \
  $(CFLAGS) \
  -include"CppuTest/MemoryLeakDetectorNewMacros.h" \

LIBS=-lCppUTest
LIB_PATH= \
  -L. -L/usr/local/lib \
# -L. -L/cygdrive/y/ModuleTest/90_Tools/CppUTestFramework/CppUTest/lib \

.PHONY: all clean

all: MemLeakDetectTests.exe

MemLeakDetectTests.exe: uses_malloc.o MemLeakDetectTests.o
	$(CXX) $(CXXFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	./$@

uses_malloc.o MemLeakDetectTests.o : Makefile uses_malloc.h

clean:
	rm -rf *.exe *.o *.dSYM *.stackdump
