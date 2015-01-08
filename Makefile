CPPUTEST_HOME = E:/CppUTest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean MockReturningStructTests AssertTests
.PRECIOUS: %.o

MockReturningStructTests: MockReturningStructTests.exe
AssertTests: AssertTests.exe

%.exe: %.o
	$(CC) -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -c $<

clean:
	rm -f *.exe; rm -f *.o;

all: MockReturningStructTests AssertTests
