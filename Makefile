#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Wno-potentially-evaluated-expression

HEADERS := Board.hpp Soldier.hpp $(wildcard *.h*)
STUDENT_SOURCES := $(filter-out $(wildcard Test*.cpp), $(filter-out $(wildcard Demo.cpp), $(wildcard *.cpp)))
STUDENT_OBJECTS := $(subst .cpp,.o,$(STUDENT_SOURCES))

run: test
	./$^

test: TestRunner.o Test_amichai.o Test_oriane_yirat.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

Test: TestCounter.o Test.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o Test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@


demo: Demo.o $(STUDENT_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

clean:
	rm -f *.o test