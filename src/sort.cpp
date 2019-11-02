#include <algorithm>
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

vector<int> InsertionSort(std::vector<int> input) {
	vector<int> output;
	output.reserve(input.size());
	for (auto ii = input.begin(); ii != input.end(); ++ii) {
		for (auto jj = output.begin(); jj != output.end(); ++jj) {
			if (*ii > *jj) {
				output.insert(jj, *ii);
				break;
			}
		}
	}
	return output;
}

int main(int argc, char* argv[]) {
	vector<int> input = CreateRandomVector();
	vector<int> output = InsertionSort(input);
	cout << "insertion sort: " << is_sorted(output.begin(), output.end()) << '\n';

	return 0;
}
