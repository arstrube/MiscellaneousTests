CXX = g++
AR = ar
INCLUDE = -Iinclude_fake -I. -I/usr/local/include
CFLAGS = -Wextra -Wall -Werror -O0
LIBS = -lLib -lCppUTest -lCppUTestExt
LIB_PATH = -L. -L/usr/local/lib

.PHONY: all clean
.SECONDARY: Lib1.i Lib2.i

all: libLib.a InlineTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $(INCLUDE) $< -o $@

%.o: %.c

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@

%.i: %.c
	$(CC) -E $(INCLUDE) $< -o $@

libLib.a: Lib1.o Lib2.o inline_fake.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

inline_fake.o Lib1.o Lib2.o InlineTests.o: Makefile

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
