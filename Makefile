SOURCE=sudoku.h generate.cpp transform.cpp solve.cpp
OBJECT=sudoku.h
CXXFLAGS=-g -Wall -std=c++0x -Ofast
CXX=g++
EXECUTABLE=generate transform solve

all:$(SOURCE) $(EXECUTABLE)

solve:solve.o $(OBJECT)
	$(CXX) -o solve $(CXXFLAGS) solve.o

generate:generate.o $(OBJECT)
	$(CXX) -o generate $(CXXFLAGS) generate.o

transform:transform.o $(OBJECT)
	$(CXX) -o transform $(CXXFLAGS) transform.o

%.o:%.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm *.o $(EXECUTABLE)
