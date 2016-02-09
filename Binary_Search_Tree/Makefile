Lab8: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o Lab8
main.o: main.cpp BinarySearchTree.h BSTI.h Test.h Node.hpp Node.h
	g++ -g -std=c++11 -Wall -c main.cpp Test.cpp Test.h Node.h BinarySearchTree.h
Test.o: Test.cpp Test.h BinarySearchTree.h
	g++ -g -std=c++11 -Wall -c Test.cpp
clean:
	rm Lab8 *.o
 