Lab1: main.o Dice.o Pokemon.o Colosseum.o
	g++ -g -std=c++11 main.o Dice.o Pokemon.o Colosseum.o -o Lab1
Dice.o: Dice.cpp Dice.h
	g++ -g -std=c++11 -c Dice.cpp
main.o: main.cpp Dice.h Pokemon.h Colosseum.h
	g++ -g -std=c++11 -c main.cpp
Pokemon.o: Pokemon.cpp Colosseum.h Pokemon.h
	g++ -g -std=c++11 -c Pokemon.cpp
Colosseum.o: Colosseum.cpp Colosseum.h Pokemon.h Dice.h
	g++ -g -std=c++11 -c Colosseum.cpp
clean:
	rm Lab1 *.o
