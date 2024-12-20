CXX = g++
CXXFLAGS = -std=c++14 -Wall -DSIGSTKSZ=16384 -I.
LDFLAGS = -lgtest -lgtest_main -pthread
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: testa_conta_palavras

testa_conta_palavras: conta_palavras.o testa_conta_palavras.o
	$(CXX) $(CXXFLAGS) $^ -o $@.exe

conta_palavras.o: conta_palavras.cpp conta_palavras.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

testa_conta_palavras.o: testa_conta_palavras.cpp conta_palavras.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

compile: testa_conta_palavras

test: testa_conta_palavras
	./testa_conta_palavras.exe

cpplint:
	cpplint --exclude=catch.hpp *.cpp *.hpp

gcov: testa_conta_palavras
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) -c conta_palavras.cpp -o conta_palavras.o
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) conta_palavras.o testa_conta_palavras.o -o testa_conta_palavras
	./testa_conta_palavras.exe
	gcov conta_palavras.cpp testa_conta_palavras.cpp

debug: testa_conta_palavras
	gdb testa_conta_palavras

cppcheck:
	cppcheck --enable=warning --std=c++14 *.cpp *.hpp

valgrind: testa_conta_palavras
	valgrind --leak-check=yes --log-file=valgrind.rpt ./testa_conta_palavras

clean:
	rm *.o *.exe *.gc* testa_conta_palavras testa_conta_palavras.exe testa_conta_palavras.o conta_palavras.o

