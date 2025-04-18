#include <cassert>
#include <limits>
#include <vector>

int Merge(std::vector<int>& A, int p, int r) {
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
    int inversions = 0;
    for (int k = p; k <= r; k++) {
        if (R[j] < L[i]) {
            A[k] = R[j];
            j++;
            inversions += (n1 - i);
        } else {
            A[k] = L[i];
            i++;
        }
    }
    return inversions;
}

int MergeSort(std::vector<int>& A, int p, int r) {
    int inversions = 0;
    if (p < r) {
        int q = (p + r) / 2;
        inversions += MergeSort(A, p, q);
        inversions += MergeSort(A, q + 1, r);
        inversions += Merge(A, p, r);
    }
    return inversions;
}

int main(void) {
    std::vector<int> A{3, 41, 52, 26, 38, 57, 9, 49};
    assert(MergeSort(A, 0, (int)A.size() - 1) == 11);
    std::vector<int> B{2, 3, 8, 6, 1};
    assert(MergeSort(B, 0, (int)B.size() - 1) == 5);
    return 0;
}