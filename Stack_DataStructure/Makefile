Lab4: main.o Test.o PreconditionViolationException.o
	g++ -g -std=c++11 -Wall main.o Test.o PreconditionViolationException.o -o Lab4
main.o: main.cpp StackInterface.h Stack.h Stack.hpp Node.hpp Node.h 
	g++ -g -std=c++11 -Wall -c main.cpp Test.cpp Test.h PreconditionViolationException.cpp  PreconditionViolationException.h
Test.o: Test.cpp Test.h Stack.h
	g++ -g -std=c++11 -Wall -c Test.cpp 
PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
clean:
	rm Lab4 *.o
