Lab2: main.o LinkedList.o Node.o Test.o
	g++ -g -std=c++11 main.o LinkedList.o Node.o Test.o -o Lab2
main.o: main.cpp Node.h LinkedList.h Test.h
	g++ -g -std=c++11 -c main.cpp
LinkedList.o: LinkedList.cpp LinkedList.h Node.h
	g++ -g -std=c++11 -c LinkedList.cpp
Node.o: Node.cpp Node.h LinkedList.h
	g++ -g -std=c++11 -c Node.cpp
Test.o: Test.cpp Test.h LinkedList.h
	g++ -g -std=c++11 -c Test.cpp
clean:
	rm Lab2 *.o
