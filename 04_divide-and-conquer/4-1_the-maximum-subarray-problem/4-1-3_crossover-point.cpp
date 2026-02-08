#include <cassert>
#include <chrono>
#include <functional>
#include <iostream>
#include <limits>
#include <optional>
#include <random>
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
FindMaximumSubarrayRecursively(const std::vector<int>& A, int low, int high) {
    if (low == high) {
        return {low, high, A[low]};
    }
    int mid = (low + high) / 2;
    auto [left_max_left, left_max_right, left_max_sum] = FindMaximumSubarrayRecursively(A, low, mid);
    auto [right_max_left, right_max_right, right_max_sum] = FindMaximumSubarrayRecursively(A, mid + 1, high);
    auto [cross_max_left, cross_max_right, cross_max_sum] = FindMaxCrossingSubarray(A, low, mid, high);
    if (left_max_sum >= right_max_sum && left_max_sum >= cross_max_sum) {
        return {left_max_left, left_max_right, left_max_sum};
    } else if (right_max_sum >= left_max_sum && right_max_sum >= cross_max_sum) {
        return {right_max_left, right_max_right, right_max_sum};
    }
    return {cross_max_left, cross_max_right, cross_max_sum};
}

template <typename F>
double time_call(F&& f) {
    const auto start = std::chrono::steady_clock::now();
    std::invoke(std::forward<F>(f));
    const auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed{finish - start};
    return elapsed.count();
}

std::vector<int> random_vector(size_t n) {
    static std::mt19937 rng{42};
    std::uniform_int_distribution<int> dist{-100, 100};

    std::vector<int> v(n);
    for (auto &x : v) {
        x = dist(rng);
    }
    return v;
}

int main(void) {
    const int trials{40};

    for (size_t n{1}; n <= 300; ++n) {
        double sum_brutal{0.0};
        double sum_recursive{0.0};

        for (int t = 0; t < trials; ++t) {
            std::vector<int> v = random_vector(n);
            sum_brutal += time_call([&] { FindMaximumSubarray(v); });
            sum_recursive += time_call([&] { FindMaximumSubarrayRecursively(v, 0, int(n - 1)); });
        }

        double avg_brutal = sum_brutal / trials;
        double avg_recursive = sum_recursive / trials;
        if (avg_recursive < avg_brutal) {
            std::cout << n << ", " << avg_brutal << ", " << avg_recursive << std::endl;
        }
    }
}
