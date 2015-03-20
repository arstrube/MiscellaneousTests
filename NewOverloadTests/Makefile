CXX = g++
CXXFLAGS = -Wextra -Wall -Werror -O2 -ffreestanding

.PHONY: all clean

all: NewOverloadTests.exe

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

NewOverloadTests.exe: NewOverloads.o NewOverloadTests.o
	$(CXX) $(CXXFLAGS) $(LIBS) $? -o $@
	./$@

NewOverloads.o NewOverloadTests.o: Makefile

clean:
	rm -rf *.exe *.o *.dSYM
