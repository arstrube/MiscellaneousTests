LIBDIRS = -LE:/CppUTest/lib
LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean

MockReturningStructTests: MockReturningStructTests.o
	$(CC) $(LIBDIRS) -o MockReturningStructTests.exe MockReturningStructTests.o $(LIBS)

MockReturningStructTests.o:	MockReturningStructTests.cpp
	$(CC) $(CFLAGS) -IE:/CppUTest/include -c MockReturningStructTests.cpp

clean:
	rm -f *.exe; rm -f *.o;

all: MockReturningStructTests
