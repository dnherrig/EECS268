lab2: main.o city.o medexe.o
	g++ -std=c++11 -g -Wall main.o city.o medexe.o -o lab2

main.o: main.cpp medexe.h 
	g++ -std=c++11 -g -Wall -c main.cpp

medexe.o: medexe.cpp medexe.h city.h
	g++ -std=c++11 -g -Wall -c medexe.cpp

city.o: city.h city.cpp
	g++ -std=c++11 -g -Wall -c city.cpp 

clean: 
	rm *.o lab2


