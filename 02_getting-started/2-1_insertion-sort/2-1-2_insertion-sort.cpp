#include <cassert>
#include <vector>

// Input: A sequence of n numbers <a_1, a_2, ..., a_n>.
// Output: A permutation <a'_1, ..., a'_n> of the input sequence such that a'_1 >= ... >= a'_n.
void InsertionSort(std::vector<int>& A) {
	for (int j = 1; j < A.size(); j++) {
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && key > A[i]) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main(void) {
	std::vector<int> A = {31, 41, 59, 26, 41, 58};
	InsertionSort(A);
    std::vector<int> T = {59, 58, 41, 41, 31, 26};
	assert(A == T);
	return 0;
}