CC = gcc
NAME = $(notdir $(PWD:%/=%))
CFLAGS = -Wextra -Wall -Werror -Wno-unused-parameter -g
.PHONY: all clean
all: $(NAME).exe
%.exe: %.o
	$(CC) $(CFLAGS) $? $(LIBS) -o $@
clean:
	rm -f *.o *.exe *.stackdump;
