CXX = g++
AR = ar
CFLAGS = -Wextra -Wall -Werror \
         -g3 -O0
LIBS=-lCppUTest
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean i

all: i ModifiedVariablyTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
i: ModifiedVariably.i
    
ModifiedVariablyTests.exe: ModifiedVariablyTests.o ModifiedVariably.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v

 ModifiedVariablyTests.o ModifiedVariably.o: Makefile ModifiedVariably.h

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
