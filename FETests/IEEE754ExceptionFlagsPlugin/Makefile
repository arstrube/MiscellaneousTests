AR = ar
LIBS =  
CXX = g++
CC = gcc
CFLAGS = -I/usr/local/include -Wextra -Wall -Werror -g \

CXXFLAGS = $(CFLAGS) -std=c++11

.PHONY: all clean

all: libIEEE754ExceptionFlagsPlugin.a

libIEEE754ExceptionFlagsPlugin.a: IEEE754ExceptionFlagsPlugin.o
	$(AR) -r -s $@ $?
    
IEEE754ExceptionFlagsPlugin.o: Makefile

clean:
	rm -f *.o *.a;