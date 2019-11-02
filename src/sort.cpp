#include <algorithm> //is_sorted
#include <iostream> //test output
#include <stack> //non-recursive merge sort
#include <random> //vector gen
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

vector<int> InsertionSort(vector<int> input) {
	vector<int> output;
	output.reserve(input.size());
	return output;
}

vector<int> Merge(vector<int> left, vector<int> right) {
	vector<int> merged;
	merged.reserve(left.size() + right.size());
	auto left_ii = left.begin();
	auto left_end = left.end();
	auto right_ii = right.begin();
	auto right_end = right.end();
	while (left_ii != left_end) {
		if (right_ii != right_end) {
			if (*left_ii < *right_ii) {
				merged.push_back(*left_ii);
				++left_ii;
			}
			else {
				merged.push_back(*right_ii);
				++right_ii;
			}
		}
		else {
			merged.push_back(*left_ii);
			++left_ii;
		}
	}
	while (right_ii != right_end) {
		merged.push_back(*right_ii);
		++right_ii;
	}
	return merged;
}

vector<int> MergeSort(vector<int> input) {
	vector<int> output;
	output.reserve(input.size());
	stack<vector<int>> merge_stack;
	for (int ii = 0; ii < input.size() - 1; ii += 2) {
		vector<int> sub;
		int left = input[ii];
		int right = input[ii + 1];
		//2 element insertion sort
		if (left < right) {
			sub.push_back(left);
			sub.push_back(right);
		}
		else {
			sub.push_back(right);
			sub.push_back(left);
		}
		merge_stack.push(sub); //each sub is sorted (2 elems)
	}
	//may have a single element left
	if (input.size() % 2 > 0) {
		vector<int> leftover = { input[input.size() - 1] };
		merge_stack.push(leftover);
	}
	//merge sorted sub arrays
	while (merge_stack.size() > 1) {// && merge_stack.size() % 2 == 0) {
		auto left = merge_stack.top();
		merge_stack.pop();
		auto right = merge_stack.top();
		merge_stack.pop();
		auto merged = Merge(left, right);
		merge_stack.push(merged);
	}
	output = merge_stack.top();	
	return output;
}

int main(int argc, char* argv[]) {
	vector<int> input = CreateRandomVector();
	cout << "input size: " << input.size() << '\n';
	vector<int> output = InsertionSort(input);
	cout << "insertion sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	output = MergeSort(input);
	cout << "merge sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	return 0;
}
