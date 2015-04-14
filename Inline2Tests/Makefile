CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror -O0 -include forced.h
LIBS=-lLib -lCppUTest
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean i

all: i libLib.a InlineTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
i: Lib1.i Lib2.i
    
libLib.a: Lib1.o Lib2.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

Lib1_Wrapper.o Lib2_Wrapper.o InlineTests.o: Makefile

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
