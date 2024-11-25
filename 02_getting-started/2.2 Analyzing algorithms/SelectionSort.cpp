#include <iostream>

using namespace std;

void SelectionSort(int A[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[i]) {
				int temp = A[j];
				A[j] = A[i];
				A[i] = temp;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	SelectionSort(A, n);
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	return 0;
}