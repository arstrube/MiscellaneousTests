CPPUTEST_HOME = /usr/local
#CPPUTEST_HOME = /e/cpputest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -g \
         -include"CppUTest/MemoryLeakDetectorNewMacros.h" \
         
TARGETS := MockReturningStructTests AutoPtrTests BugTests CountedTestTests \
           FabsTests OutParamTests OneTimeThrowAwayTests

.PHONY: all clean $(TARGETS)

all: $(TARGETS)

MockReturningStructTests: MockReturningStructTests.exe
AutoPtrTests: AutoPtrTests.exe
BugTests: BugTests.exe
CountedTestTests: CountedTestTests.exe
FabsTests: FabsTests.exe
OutParamTests: OutParamTests.exe
OneTimeThrowAwayTests: OneTimeThrowAwayTests.exe

%.exe: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@
	./$@

clean:
	rm -f *.exe *.layout *.depend *.stackdump *.7z;
