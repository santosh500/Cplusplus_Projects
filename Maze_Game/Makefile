Lab9: main.o MazeCreationException.o MazeReader.o MazeWalker.o Position.o Test.o
	g++ -g -std=c++11 main.o MazeCreationException.o MazeReader.o Position.o Test.o MazeWalker.o -o Lab9
main.o: main.cpp MazeCreationException.h MazeReader.h MazeWalker.h Position.h Test.h
	g++ -g -std=c++11 -Wall -c main.cpp
MazeCreationException.o: MazeCreationException.cpp MazeCreationException.h 
	g++ -g -std=c++11 -Wall -c MazeCreationException.cpp
MazeReader.o: MazeReader.cpp MazeReader.h 
	g++ -g -std=c++11 -Wall -c MazeReader.cpp 
MazeWalker.o: MazeWalker.cpp MazeWalker.h 
	g++ -g -std=c++11 -Wall -c MazeWalker.cpp
Position.o: Position.cpp Position.h
	g++ -g -std=c++11 -Wall -c Position.cpp
Test.o: Test.cpp Test.h
	g++ -g -std=c++11 -Wall -c Test.cpp
clean:
	rm Lab9 *.o 
