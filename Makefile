CPPUTEST_HOME = E:/CppUTest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean

MockReturningStructTests: MockReturningStructTests.o
	$(CC) -L$(CPPUTEST_HOME)/lib -o MockReturningStructTests.exe MockReturningStructTests.o $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -c $<

clean:
	rm -f *.exe; rm -f *.o;

all: MockReturningStructTests
