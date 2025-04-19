#include <cassert>
#include <limits>
#include <optional>
#include <tuple>
#include <vector>

std::tuple<int, int, int> FindMaximumSubarray(const std::vector<int>& A) {
    size_t n = A.size();
    int max_left = 0;
    int max_right = 0;
    int max_sum = A[0];

    int prev_max_left = 0;
    int prev_max_sum = A[0];

    for (size_t j = 1; j < n; j++) {
        int cur_max_left = prev_max_left;
        int cur_max_sum = prev_max_sum + A[j];
        if (A[j] > cur_max_sum) {
            cur_max_left = j;
            cur_max_sum = A[j];
        }

        if (cur_max_sum > max_sum) {
            max_left = cur_max_left;
            max_right = j;
            max_sum = cur_max_sum;
        }

        prev_max_left = cur_max_left;
        prev_max_sum = cur_max_sum;
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