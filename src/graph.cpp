#include "Graph.hpp"

int main(int argc, char* argv[]) {
	Graph<int> tst(100);
	tst.AddNode(100, 101);
	tst.AddNode(100, 103);
	tst.AddNode(101, 100); //ignored
	tst.AddNode(103, 107);
	tst.Print();
	return 0;
}
