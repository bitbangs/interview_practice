#include <iostream>
#include <random>
#include <vector>
using namespace std;

random_device rand_dev;
mt19937 rand_gen(rand_dev());
uniform_int_distribution<> rand_dis(2, 1000);

int GenerateRandomInt() {
	return rand_dis(rand_gen);
}

vector<int> CreateRandomVector() {
	vector<int> random_vec;
	int size = GenerateRandomInt();
	
	random_vec.reserve(size);
	for (int ii = 0; ii < size; ++ii) {
		random_vec.push_back(GenerateRandomInt());
	}

	return random_vec;
}

int main(int argc, char* argv[]) {
	vector<int> input = CreateRandomVector();
	//cout << "insertion sort: " << InsertionSort(input) << '\n';
	for (int ii : input) {	
		cout << ii << '\n';
	}

	return 0;
}
