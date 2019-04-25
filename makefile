
all:
	g++ -Wall -std=c++11 main.cpp -o wordcounts

clean:
	rm *.o wordcounts
