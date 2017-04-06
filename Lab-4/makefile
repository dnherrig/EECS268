lab4: main.o BuildingExecutive.o PreconditionViolationException.o
	g++ -std=c++11 -g -Wall main.o BuildingExecutive.o PreconditionViolationException.o -o lab4

main.o: main.cpp BuildingExecutive.h BuildingExecutive.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

BuildingExecutive.o: BuildingExecutive.cpp BuildingExecutive.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c BuildingExecutive.cpp

PreconditionViolationException.o: PreconditionViolationException.cpp PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp

clean:
	rm *.o lab4
