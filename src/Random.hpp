#include <random>
#include <vector>
using namespace std;

random_device rand_dev;
mt19937 rand_gen(rand_dev());
uniform_int_distribution<> rand_dis(1, 2000);

class Random {
public:
	int GenerateRandomInt() {
		return rand_dis(rand_gen);
	}

	vector<int> GenerateRandomVector() {
		vector<int> random_vec;
		int size = this->GenerateRandomInt();
		random_vec.reserve(size);

		for (int ii = 0; ii < size; ++ii) {
			random_vec.push_back(this->GenerateRandomInt());
		}

		return random_vec;
	}
};
