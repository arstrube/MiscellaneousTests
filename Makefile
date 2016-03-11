#CPPUTEST_HOME = /usr/local
#CPPUTEST_HOME = /e/cpputest
CPPUTEST_HOME = /cygdrive/c/data/00_Dev/05_CppUTest/cpputest

LIBS = -lCppUTest -lCppUTestExt
CC = g++
CFLAGS = -Wextra -Wall -Werror -Wfloat-conversion -g3 -O0 \
         -std=c++11 \
         -include"CppUTest/MemoryLeakDetectorNewMacros.h" \
         
TARGETS := BugTests MockDoesntFailTests MockMultiFailTests MockReturningStructTests \
           AutoPtrTests CountedTestTests FabsTests OutParamTests \
           OneTimeThrowAwayTests

.PHONY: all clean $(TARGETS)

all: $(TARGETS)

MockDoesntFailTests: MockDoesntFailTests.exe
MockMultiFailTests: MockMultiFailTests.exe
MockReturningStructTests: MockReturningStructTests.exe
AutoPtrTests: AutoPtrTests.exe
BugTests: BugTests.exe
CountedTestTests: CountedTestTests.exe
FabsTests: FabsTests.exe
OutParamTests: OutParamTests.exe
OneTimeThrowAwayTests: OneTimeThrowAwayTests.exe

%.exe: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@

clean:
	rm -f *.exe *.layout *.depend *.stackdump *.7z;
    
$(TARGETS): 
	./$<
