CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror -Wno-unused-function -O0
LIBS=-lLib -lCppUTest
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean

all: libLib.a InlineTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
libLib.a: Lib1_Wrapper.o Lib2_Wrapper.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

Lib1_Wrapper.o Lib2_Wrapper.o InlineTests.o: Makefile

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
