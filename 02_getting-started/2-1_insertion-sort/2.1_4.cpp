#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int A[n], B[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	int C[n + 1];
	int carry = 0;
	for (int i = n; i > 0; i--) {
		int j = i - 1;
		int sum = A[j] + B[j] + carry;
		C[i] = sum % 2;
		carry = sum / 2;
	}
	C[0] = carry;
	for (int i = 0; i <= n; i++) cout << C[i];
	return 0;
}