#include <algorithm>
#include <cassert>
#include <vector>

void SelectionSort(std::vector<int>& A) {
    for (int i = 0; i + 1 < A.size(); i++) {
        int k = i;
        for (int j = i + 1; j < A.size(); j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        if (k > i) {
            std::swap(A[i], A[k]);
        }
    }
}

int main(void) {
    std::vector<int> A = {31, 41, 59, 26, 41, 58};
    SelectionSort(A);
    std::vector<int> T = {26, 31, 41, 41, 58, 59};
    assert(A == T);
    return 0;
}