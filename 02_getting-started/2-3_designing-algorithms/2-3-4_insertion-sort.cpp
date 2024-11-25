#include <cassert>
#include <vector>

void Insert(std::vector<int>& A, int r) {
    int l = r - 1;
    int key = A[r];
    while (l >= 0 && A[l] > key) {
        A[l + 1] = A[l];
        l--;
    }
    A[l + 1] = key;
}

void InsertionSort(std::vector<int>& A, int r) {
    if (r > 0) {
        InsertionSort(A, r - 1);
        Insert(A, r);
    }
}

int main(void) {
    std::vector<int> A = {3, 41, 52, 26, 38, 57, 9, 49};
    InsertionSort(A, A.size() - 1);
    std::vector<int> T = {3, 9, 26, 38, 41, 49, 52, 57};
    assert(A == T);
    return 0;
}