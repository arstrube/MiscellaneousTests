CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror -O0 -include forced.h
LIBS=-lInlineLib -lCppUTest
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean

all: libInlineLib.a InlineTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

libInlineLib.a: InlineLib1.o InlineLib2.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

InlineLib1.o InlineLib2.o InlineTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYM
