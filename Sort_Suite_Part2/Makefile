Lab7: main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o Test.o
	g++ -g -std=c++11 main.o SortDriver.o NumberFileDriver.o Test.o NumberFileGenerator.o -o Lab7
main.o: main.cpp Sorts.h Sorts.hpp SortDriver.h NumberFileDriver.h NumberFileGenerator.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp SortDriver.cpp SortDriver.h NumberFileGenerator.cpp NumberFileGenerator.h NumberFileDriver.cpp NumberFileDriver.h Test.h Test.cpp
SortDriver.o: SortDriver.cpp SortDriver.h
	g++ -g -std=c++11 -Wall -c SortDriver.cpp
NumberFileGenerator.o: NumberFileGenerator.cpp NumberFileGenerator.h
	g++ -g -std=c++11 -Wall -c NumberFileGenerator.cpp
NumberFileDriver.o: NumberFileDriver.cpp NumberFileDriver.h NumberFileGenerator.h
	g++ -g -std=c++11 -Wall -c NumberFileDriver.cpp
Test.o: Test.cpp Test.h 
	g++ -g -std=c++11 -Wall -c Test.cpp
clean:
	rm Lab7 *.o
