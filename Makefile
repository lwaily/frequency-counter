CXX=g++
CXXFLAGS?=-Wall -Wmaybe-uninitialized -pedantic -Werror -g -O0 -std=c++17
OUTFILES=freq-counter

all: $(OUTFILES)

exe: freq-counter.cpp
	$(CXX) $(CXXFLAGS) -o freq-counter freq-counter.cpp

clean:
	$(RM) $(OUTFILES) *.o

