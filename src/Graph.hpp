#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

template <class T>
class Graph {
private:
	map<T, set<T>> adjacent;
public:
	Graph() = delete;
	Graph(T root) {
		this->adjacent[root] = set<T>();
	}

	void AddNode(T existing, T add_me) {
		if (this->adjacent.count(add_me) == 0 || this->adjacent.at(add_me).count(existing) == 0) { //no circular references
			if (this->adjacent.count(existing) > 0) {
				this->adjacent.at(existing).insert(add_me);
			}
			else {
				this->adjacent[existing] = set<T>({add_me});
			}
		}
	}

	void Print() {
		for (pair<T, set<T>> ii : this->adjacent) {
			cout << ii.first << '\n';
			for (T jj : ii.second) {
				cout << '\t' << jj << '\n';
			}
		}
	}
};
