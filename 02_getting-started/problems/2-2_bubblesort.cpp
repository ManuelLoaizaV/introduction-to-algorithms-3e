#include <algorithm>
#include <cassert>
#include <vector>

void Bubblesort(std::vector<int>& A) {
    for (int i = 0; i < A.size() - 1; i++) {
        for (int j = A.size() - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                std::swap(A[j], A[j - 1]);
            }
        }
    }
}

int main(void) {
    std::vector<int> A = {3, 41, 52, 26, 38, 57, 9, 49};
    Bubblesort(A);
    std::vector<int> T = {3, 9, 26, 38, 41, 49, 52, 57};
    assert(A == T);
    return 0;
}