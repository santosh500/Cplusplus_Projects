Lab6: main.o Test.o
	g++ -g -std=c++11 main.o Test.o -o Lab6
main.o: main.cpp Sorts.h Sorts.hpp Test.h
	g++ -g -std=c++11 -c main.cpp Test.h Test.cpp
Test.o: Test.cpp Test.h Sorts.h
	g++ -g -std=c++11 -c Test.cpp
clean:
	rm Lab6 *.o
