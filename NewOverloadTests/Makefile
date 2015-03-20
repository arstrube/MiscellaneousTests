LIBS =
CC = g++
LD = g++
CFLAGS = -Wextra -Wall -Werror -O2

.PHONY: all clean

all: NewOverloadTests.exe

%.o: %.cpp
	$(CC) -c $(CFLAGS) -ffreestanding $< -o $@

NewOverloadTests.exe: NewOverloads.o NewOverloadTests.o
	$(LD) $(CFLAGS) $(LIBS) $? -o $@
	./$@

NewOverloads.o NewOverloadTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYM
