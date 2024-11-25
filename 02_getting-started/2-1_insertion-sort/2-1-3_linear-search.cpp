#include <cassert>
#include <optional>
#include <vector>

// Input: A sequence of n numbers A = <a_1, ..., a_n> and a value v.
// Output: An index i such that v = A[i] or the special value NIL if v does not appear in A.
std::optional<int> LinearSearch(const std::vector<int>& A, int v) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == v) {
            return i;
        }
    }
    return std::nullopt;
}

int main(void) {
    std::vector<int> A = {31, 41, 59, 26, 41, 58};
    assert(LinearSearch(A, 41) == 1);
    assert(LinearSearch(A, 26) == 3);
    assert(LinearSearch(A, 58) == 5);
    assert(!LinearSearch(A, 100).has_value());
    return 0;
}