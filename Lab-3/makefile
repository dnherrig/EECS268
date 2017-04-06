lab3: main.o MathTools.o exec.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o
	g++ -std=c++11 -g -Wall main.o MathTools.o exec.o NegativeDiscriminant.o NoIntersection.o CannotDetermineRoomDimensions.o -o lab3

main.o: main.cpp MathTools.h exec.h
	g++ -std=c++11 -g -Wall -c main.cpp

exec.o: exec.cpp exec.h MathTools.h
	g++ -std=c++11 -g -Wall -c exec.cpp

MathTools.o: MathTools.h MathTools.cpp NegativeDiscriminant.h NoIntersection.h CannotDetermineRoomDimensions.h
	g++ -std=c++11 -g -Wall -c MathTools.cpp

NegativeDiscriminant.o: NegativeDiscriminant.h NegativeDiscriminant.cpp
	g++ -std=c++11 -g -Wall -c NegativeDiscriminant.cpp

NoIntersection.o: NoIntersection.h NoIntersection.cpp
	g++ -std=c++11 -g -Wall -c NoIntersection.cpp

CannotDetermineRoomDimensions.o: CannotDetermineRoomDimensions.h CannotDetermineRoomDimensions.cpp
	g++ -std=c++11 -g -Wall -c CannotDetermineRoomDimensions.cpp

clean:
	rm *.o lab3
