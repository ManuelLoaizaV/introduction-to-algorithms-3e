#include <cassert>
#include <vector>

// Input: Two sequences of n digits A = <a_1, ..., a_n> and B = <b_1, ..., b_n>.
// Output: A sequence of n+1 numbers C = <c_1, ..., c_{n+1}> storing the sum of A and B.
std::vector<int> Add(const std::vector<int>& A, const std::vector<int>& B) {
	std::vector<int> C(A.size() + 1, 0);
	int carry = 0;
	for (int i = A.size() - 1; i >= 0; i--) {
		int sum = A[i] + B[i] + carry;
		C[i + 1] = sum % 10;
		carry = sum / 10;
	}
	if (carry > 0) {
		C[0] = carry;
	}
	return C;
}

int main(void) {
	std::vector<int> A = {7, 4, 5, 2};
	std::vector<int> B = {2, 8, 1, 9};
	std::vector<int> T = {1, 0, 2, 7, 1};
	assert(Add(A, B) == T);
	return 0;
}