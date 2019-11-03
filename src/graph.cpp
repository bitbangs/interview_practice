#include <vector>
#include "Graph.hpp"
#include "Random.hpp"

int main(int argc, char* argv[]) {
	Random random;
	int graph_max = 100;
	Graph<int> tst(random.GenerateRandomInt() % graph_max);
	vector<int> random_nodes = random.GenerateRandomVector();
	for (int ii = 0; ii < random_nodes.size() - 1; ii += 2) { //be sure not to index out of bounds
		int node = random_nodes[ii] % graph_max;
		int connection = random_nodes[ii + 1] % graph_max;
		tst.AddNode(node, connection);
	}
	tst.Print();
	return 0;
}
