#CPPUTEST_HOME = /usr/local
CPPUTEST_HOME = /e/cpputest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g
TARGETS := MockReturningStructTests AutoPtrTests BugTests CountedTestTests FabsTests OutParamTests

.PHONY: all clean $(TARGETS)

all: $(TARGETS)

MockReturningStructTests: MockReturningStructTests.exe
AutoPtrTests: AutoPtrTests.exe
BugTests: BugTests.exe
CountedTestTests: CountedTestTests.exe
FabsTests: FabsTests.exe
OutParamTests: OutParamTests.exe

%.exe: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@
	./$@

clean:
	rm -f *.exe;
