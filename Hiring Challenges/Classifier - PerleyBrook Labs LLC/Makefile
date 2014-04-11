all: $(patsubst %.cpp, %, $(wildcard *.cpp))
%.out: %.cpp Makefile
    g++ $< -o $@ -std=c++0x