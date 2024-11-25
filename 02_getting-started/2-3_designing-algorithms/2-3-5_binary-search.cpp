#include <cassert>
#include <optional>
#include <vector>

std::optional<int> BinarySearch(int v, int p, int r, const std::vector<int>& A) {
    if (p > r) {
        return std::nullopt;
    }
    int q = (p + r) / 2;
    if (v == A[q]) {
        return q;
    } else if (v < A[q]) {
        return BinarySearch(v, p, q - 1, A);
    } else {
        return BinarySearch(v, q + 1, r, A);
    }
}

int main(void) {
    std::vector<int> A = {3, 9, 26, 38, 41, 49, 52, 57};
    assert(BinarySearch(3, 0, A.size() - 1, A) == 0);
    assert(BinarySearch(38, 0, A.size() - 1, A) == 3);
    assert(BinarySearch(52, 0, A.size() - 1, A) == 6);
    assert(BinarySearch(57, 0, A.size() - 1, A) == 7);
    assert(!BinarySearch(4, 0, A.size() - 1, A).has_value());
    assert(!BinarySearch(100, 0, A.size() - 1, A).has_value());
    return 0;
}
