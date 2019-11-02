#include <algorithm> //is_sorted
#include <iostream> //test output
#include <stack> //non-recursive merge sort
#include <random> //vector gen
#include <vector>
using namespace std;

random_device rand_dev;
mt19937 rand_gen(rand_dev());
uniform_int_distribution<> rand_dis(2, 2000);

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

vector<int> SelectionSort(vector<int> input) {
	vector<int> output = input;
	for (int ii = 0; ii < output.size() - 1; ++ii) {
		int min_index = ii;
		int jj = ii + 1;
		for (; jj < output.size(); ++jj) {
			if (output[min_index] > output[jj]) {	
				min_index = jj;
			}
		}
		//swap to ii if needed
		if (output[min_index] != output[ii]) {
			int temp = output[ii];
			output[ii] = output[min_index];
			output[min_index] = temp;
		}
	}
	return output;
}

vector<int> InsertionSort(vector<int> input) {
	vector<int> output;
	output.reserve(input.size());
	output.push_back(input[0]);
	for (int ii = 1; ii < input.size(); ++ii) {
		int output_size = output.size();
		for (int jj = 0; jj < output_size; ++jj) {
			if (output[jj] >= input[ii]) {
				output.insert(output.begin() + jj, input[ii]);
				break; //stop checking
			}
			else if (jj == output.size() - 1) {
				output.insert(output.end(), input[ii]);
			}
		}
	}
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

void Heapify(vector<int>& heap_me, int ii, int end) {
	int left_ii = ii * 2;
	int right_ii = left_ii + 1;
	int max_ii = ii;
	if (left_ii < end && heap_me[left_ii] > heap_me[max_ii]) {
		max_ii = left_ii;
	}
	if (right_ii < end && heap_me[right_ii] > heap_me[max_ii]) {
		max_ii = right_ii;
	}
	if (max_ii != ii) {
		//swap
		int temp = heap_me[ii];
		heap_me[ii] = heap_me[max_ii];
		heap_me[max_ii] = temp;
		Heapify(heap_me, max_ii, end); //recurse only because we had to swap so now subtree may need reheaping
	}
}

vector<int> HeapSort(vector<int> input) {
	vector<int> output = input;
	for (int ii = output.size() / 2; ii >= 0; --ii) {
		Heapify(output, ii, output.size());
	}
	for (int ii = output.size() - 1; ii > 0; --ii) {
		//put max of heap at end
		int temp = output[0];
		output[ii] = output[0]; //inserts max into sorted place
		output[0] = temp; //possibly invalidate heap
		//heapify all but max that was just moved
		Heapify(output, 0, ii - 1);
	}
	return output;
}

int main(int argc, char* argv[]) {
	vector<int> input = CreateRandomVector();
	cout << "input size: " << input.size() << '\n';
	vector<int> output = SelectionSort(input);
	cout << "selection sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	output = InsertionSort(input);
	cout << "insertion sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	output = MergeSort(input);
	cout << "merge sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	output = HeapSort(input);
	cout << "heap sort: " << is_sorted(output.begin(), output.end()) << '\n';
	cout << "output size: " << output.size() << '\n';
	return 0;
}
