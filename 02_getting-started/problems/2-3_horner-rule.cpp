#include <cassert>
#include <vector>

long long Horner(const std::vector<long long>& a, const long long& x) {
    long long y{0LL};
    for (int i = (int)a.size() - 1; i >= 0; i--) {
        y = a[i] + x * y;
    }
    return y;
}

int main(void) {
    std::vector<long long> a{2LL, 0LL, -2LL, 1LL, 2LL, -7LL};
    assert(Horner(a, -2LL) == 242LL);
    assert(Horner(a, 0LL) == 2LL);
    assert(Horner(a, 2LL) == -190LL);
    return 0;
}
