LIBS := -lCppUTest -lCppUTestExt -lIEEE754ExceptionFlagsPlugin
CXX := g++
CC := gcc
CFLAGS := -g3 -L/usr/local/lib -LIEEE754ExceptionFlagsPlugin \
         -Wextra -Wall -Werror -g \
         -frounding-math \
         -IIEEE754ExceptionFlagsPlugin \

CXXFLAGS := $(CFLAGS) -std=c++11
TESTS := FETests.exe
DEMO := FEDemoTests.exe

.PHONY: all check clean demo

check: $(TESTS)
	./$< -v
    
demo: $(DEMO)
	./$< -v

all: $(TESTS) $(DEMO)

$(TESTS): FETests.o FETests_c.o
	$(CXX) $(CFLAGS) $? $(LIBS) -o $@

$(DEMO): FEDemoTests.o FETests_c.o
	$(CXX) $(CFLAGS) $? $(LIBS) -o $@

FEDemoTests.o FETests.o FETests_c.o: Makefile

clean:
	rm -f *.o *.exe *.stackdump;
