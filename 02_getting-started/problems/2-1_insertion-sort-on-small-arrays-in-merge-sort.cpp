#include <cassert>
#include <cmath>
#include <limits>
#include <vector>

void InsertionSort(std::vector<int>& A, int l, int r) {
	for (int j = l; j <= r; j++) {
		int key = A[j];
		int i = j - 1;
		while (i >= l && A[i] > key) {
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

void Merge(std::vector<int>& A, int pi, int ri, int k) {
    int qi = (pi + ri) / 2;
    int p = k * pi;
    int q = k * qi + k - 1;
    int r = std::min(k * ri + k - 1, (int)A.size() - 1);
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> L(n1 + 1);
    std::vector<int> R(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(std::vector<int>& A, int p, int r, int k) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q, k);
        MergeSort(A, q + 1, r, k);
        Merge(A, p, r, k);
    } else if (p == r) {
        InsertionSort(A, k * p, std::min(k * r + k - 1, (int)A.size() - 1));
    }
}

int main(void) {
    std::vector<int> A = {34, 7, 23, 32, 5, 62, 78, 19, 44, 91, 12, 8, 56, 29, 3, 47};
    int n = (int)A.size();
    int k = (int)std::log2(n) + 1;
    int m = (n + k - 1) / k;
    MergeSort(A, 0, m - 1, k);
    std::vector<int> T = {3, 5, 7, 8, 12, 19, 23, 29, 32, 34, 44, 47, 56, 62, 78, 91};
    assert(A == T);
    return 0;
}