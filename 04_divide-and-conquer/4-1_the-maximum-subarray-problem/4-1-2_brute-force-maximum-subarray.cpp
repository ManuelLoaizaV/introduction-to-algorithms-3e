#include <cassert>
#include <limits>
#include <optional>
#include <tuple>
#include <vector>

std::tuple<std::optional<int>, std::optional<int>, int>
FindMaximumSubarray(const std::vector<int>& A) {
    size_t n = A.size();
    int max_sum = std::numeric_limits<int>::min();
    std::optional<int> max_left, max_right;
    for (size_t i = 0; i < n; i++) {
        int sum = 0;
        for (size_t j = i; j < n; j++) {
            sum += A[j];
            if (sum > max_sum) {
                max_left = i;
                max_right = j;
                max_sum = sum;
            }
        }
    }
    return {max_left, max_right, max_sum};
}

int main(void) {
    {
        std::vector<int> A{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
        auto [max_left, max_right, max_sum] = FindMaximumSubarray(A);
        assert(max_left == 7);
        assert(max_right == 10);
        assert(max_sum == 43);
    }

    {
        std::vector<int> B{-31, -41, -59, -26, -53, -58};
        auto [max_left, max_right, max_sum] = FindMaximumSubarray(B);
        assert(max_left == 3);
        assert(max_right == 3);
        assert(max_sum == -26);
    }
    return 0;
}