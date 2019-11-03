graph: graph.o
	g++ bin/graph.o -o bin/graph

graph.o: src/graph.cpp
	g++ -c -g src/graph.cpp -o bin/graph.o

sort: sort.o
	g++ bin/sort.o -o bin/sort

sort.o: src/sort.cpp
	g++ -c -g src/sort.cpp -o bin/sort.o

clean:
	rm -rf bin/sort.o bin/sort bin/graph.o bin/graph
