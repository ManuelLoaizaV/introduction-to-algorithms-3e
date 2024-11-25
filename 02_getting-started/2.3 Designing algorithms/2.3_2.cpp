#include <iostream>

using namespace std;

void Merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1];
	int R[n2];
	for (int i = 0; i < n1; i++) L[i] = A[p + i];
	for (int i = 0; i < n2; i++) R[i] = A[q + 1 + i];
	int i = 0;
	int j = 0;
	for (int k = p; k <= r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
			if (i == n1) {
				for (int l = j; l < n2; l++) A[k + 1 + l - j] = R[l];
				break;
			}
		} else {
			A[k] = R[j];
			j++;
			if (j == n2) {
				for (int l = i; l < n1; l++) A[k + 1 + l - i] = L[l];
				break;
			}
		}
	}
}

void MergeSort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main() {
	int n;
	cin >> n;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	MergeSort(A, 0, n - 1);
	for (int i = 0; i < n; i++) cout << A[i] << " ";
	return 0;
}