CPPUTEST_HOME = /usr/local

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean MockReturningStructTests AutoPtrTests CountedTestTests FabsTests OutParamTests

all: MockReturningStructTests AutoPtrTests CountedTestTests FabsTests OutParamTests

MockReturningStructTests: MockReturningStructTests.exe
AutoPtrTests: AutoPtrTests.exe
CountedTestTests: CountedTestTests.exe
FabsTests: FabsTests.exe
OutParamTests: OutParamTests.exe

%.exe: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@
	./$@

clean:
	rm -f *.exe;
