CC = gcc
CFLAGS = -Wextra -Wall -Werror -Wno-unused-parameter -g
.PHONY: all clean
all: Fork4GdbTests.exe
%.exe: %.o
	$(CC) $(CFLAGS) $? $(LIBS) -o $@
clean:
	rm -f *.o *.exe *.stackdump;
