AR = ar
LIBS =  
CXX = g++
CC = gcc
CFLAGS = -L/usr/local/lib -Wextra -Wall -Werror -g \
         -frounding-math

CXXFLAGS = $(CFLAGS) -std=c++11

.PHONY: all clean

all: libIEEE754ExceptionFlagsPlugin.a

libIEEE754ExceptionFlagsPlugin.a: IEEE754ExceptionFlagsPlugin.o
	$(AR) -r -s $@ $?
    
IEEE754ExceptionFlagsPlugin.o: Makefile

clean:
	rm -f *.o *.a;