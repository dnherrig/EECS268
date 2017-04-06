lab1: main.o voterreg.o exec.o
	g++ -std=c++11 -g -Wall main.o voterreg.o exec.o -o lab1

main.o: main.cpp voterreg.h
	g++ -std=c++11 -g -Wall -c main.cpp

exec.o: exec.cpp exec.h
	g++ -std=c++11 -g -Wall -c exec.cpp

voterreg.o: voterreg.h voterreg.cpp
	g++ -std=c++11 -g -Wall -c voterreg.cpp 

clean: 
	rm *.o lab1

