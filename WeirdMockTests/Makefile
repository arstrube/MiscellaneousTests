CXX = g++
AR = ar
CFLAGS = -g3 -Wextra -Wall -Werror -O0 -I/usr/local/include
LIBS= -lCppUTest -lCppUTestExt
LIB_PATH=-L. -L/usr/local/lib

.PHONY: all clean i

all: i WeirdMockTests.exe

%.o: %.cpp
	$(CXX) -c $(CFLAGS) $< -o $@

%.o: %.i
	$(CC) -c $(CFLAGS) $< -o $@
    
%.i: %.c
	$(CC) -E $(CFLAGS) $< -o $@
    
WeirdMockTests.exe: WeirdMockTests.o
	$(CXX) $(CFLAGS) $(LIB_PATH) $? $(LIBS) -o $@
	echo; ./$@ -v -c

WeirdMockTests.o: Makefile

clean:
	rm -rf *.a *.dSYM *.exe *.i *.o
