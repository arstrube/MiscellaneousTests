CPPUTEST_HOME = /usr/local

LIBS = -lCppUTest -lCppUTestExt -std=c++11
CC = g++
CFLAGS = -Wextra -Wall -Werror -g

.PHONY: all clean

all: EnumTests.exe

%.exe: %.cpp
	$(CC) $(CFLAGS) -I$(CPPUTEST_HOME)/include -L$(CPPUTEST_HOME)/lib $< $(LIBS) -o $@
	./$@

clean:
	rm -f *.exe;
