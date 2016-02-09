Lab3: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o Lab3
main.o: main.cpp DoubleLinkedList.hpp DoubleLinkedList.h Node.h Node.hpp 
	g++ -g -std=c++11 -Wall -c main.cpp Test.cpp Test.h
Test.o: Test.cpp Test.h
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm Lab3 *.o
