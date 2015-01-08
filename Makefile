MockReturningStructTests: MockReturningStructTests.o
	g++ -LE:/CppUTest/lib -o MockReturningStructTests.exe MockReturningStructTests.o -lCppUTest -lCppUTestExt

MockReturningStructTests.o:	MockReturningStructTests.cpp
	g++ -Wextra -Wall -Werror -g -IE:/CppUTest/include -c MockReturningStructTests.cpp

clean:
	rm -f *.exe; rm -f *.o;

all: MockReturningStructTests