CPPUTEST_HOME = E:/CppUTest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean MockReturningStructTests AutoPtrTests CountedTestTests FabsTests OutParamTests
.PRECIOUS: %.o

all: MockReturningStructTests AutoPtrTests CountedTestTests FabsTests OutParamTests

MockReturningStructTests: MockReturningStructTests.exe
AutoPtrTests: AutoPtrTests.exe
CountedTestTests: CountedTestTests.exe
FabsTests: FabsTests.exe
OutParamTests: OutParamTests.exe

%.exe: %.o
	$(CC) -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@
	./$@

%.o: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -c $<

clean:
	rm -f *.exe; rm -f *.o;
