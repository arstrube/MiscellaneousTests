CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror -g3 -O0 -include forced.h
LIBS=-lInlineLib -lCppUTest
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean i

all: i libInlineLib.a InlineTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
i: InlineLib1.i InlineLib2.i InlineLib_macro.i
    
libInlineLib.a: InlineLib1.o InlineLib2.o InlineLib_macro.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

InlineLib1.o InlineLib2.o InlineTests.o InlineLib_macro.o: Makefile forced.h

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
