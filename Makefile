all: date

date: date.cpp
	g++ -g -o date date.cpp

clean:
	rm date