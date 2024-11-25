#include <cassert>
#include <vector>

void Merge(std::vector<int>& A, int p, int r) {
    int q = (p + r) / 2;
    int n1 = q - p + 1;
    int n2 = r - q;
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    if (i == n1) {
        while (j < n2) {
            A[k] = R[j];
            j++;
            k++;
        }
    } else {
        while (i < n1) {
            A[k] = L[i];
            i++;
            k++;
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