all: main

main: main.o Clock.o
	g++ main.o Clock.o -o main

main.o: main.cpp
	g++ -c main.cpp

Clock.o: Clock.cpp
	g++ -c Clock.cpp

clean:
	rm -f *.o main

run: main
	./main