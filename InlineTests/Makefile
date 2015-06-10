CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror \
         -g3 -O0 \
         -DINLINE=#inline # uncomment to compile inline   
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
    
i: InlineLib-1.i InlineLib-2.i inline.i
    
libInlineLib.a: InlineLib-1.o InlineLib-2.o inline.o
	$(AR) -r -s $@ $?

InlineTests.exe: InlineTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

 inline.o InlineLib-1.o InlineLib-2.o InlineTests.o: Makefile inline.h InlineLib.h

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
