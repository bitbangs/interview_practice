sort: sort.o
	g++ bin/sort.o -o bin/sort

sort.o: src/sort.cpp
	g++ -c src/sort.cpp -o bin/sort.o

clean:
	rm -rf bin/sort.o bin/sort
