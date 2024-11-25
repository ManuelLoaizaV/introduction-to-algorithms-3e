#include <cassert>
#include <limits>
#include <vector>

void Merge(std::vector<int>& A, int p, int r) {
    int q = (p + r) / 2;
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

void MergeSort(std::vector<int>& A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, r);
    }
}

int main(void) {
    std::vector<int> A = {3, 41, 52, 26, 38, 57, 9, 49};
    MergeSort(A, 0, A.size() - 1);
    std::vector<int> T = {3, 9, 26, 38, 41, 49, 52, 57};
    assert(A == T);
    return 0;
}