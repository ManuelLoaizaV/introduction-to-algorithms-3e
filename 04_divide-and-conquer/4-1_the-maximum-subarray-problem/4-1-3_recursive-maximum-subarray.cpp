#include <cassert>
#include <limits>
#include <optional>
#include <tuple>
#include <vector>

std::tuple<std::optional<int>, std::optional<int>, int>
FindMaxCrossingSubarray(
    const std::vector<int>& A,
    int low, int mid, int high
) {
    int left_sum = std::numeric_limits<int>::min();
    std::optional<int> max_left;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = std::numeric_limits<int>::min();
    std::optional<int> max_right;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return {max_left, max_right, left_sum + right_sum};
}

std::tuple<std::optional<int>, std::optional<int>, int>
FindMaximumSubarray(const std::vector<int>& A, int low, int high) {
    if (low == high) {
        return {low, high, A[low]};
    }
    int mid = (low + high) / 2;
    auto [left_max_left, left_max_right, left_max_sum] = FindMaximumSubarray(A, low, mid);
    auto [right_max_left, right_max_right, right_max_sum] = FindMaximumSubarray(A, mid + 1, high);
    auto [cross_max_left, cross_max_right, cross_max_sum] = FindMaxCrossingSubarray(A, low, mid, high);
    if (left_max_sum >= right_max_sum && left_max_sum >= cross_max_sum) {
        return {left_max_left, left_max_right, left_max_sum};
    } else if (right_max_sum >= left_max_sum && right_max_sum >= cross_max_sum) {
        return {right_max_left, right_max_right, right_max_sum};
    }
    return {cross_max_left, cross_max_right, cross_max_sum};
}

int main(void) {
    {
        std::vector<int> A{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
        auto [max_left, max_right, max_sum] = FindMaximumSubarray(A, 0, (int)A.size() - 1);
        assert(max_left == 7);
        assert(max_right == 10);
        assert(max_sum == 43);
    }

    {
        std::vector<int> B{-31, -41, -59, -26, -53, -58};
        auto [max_left, max_right, max_sum] = FindMaximumSubarray(B, 0, (int)B.size() - 1);
        assert(max_left == 3);
        assert(max_right == 3);
        assert(max_sum == -26);
    }
    return 0;
}