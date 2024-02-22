#include <iostream>
#include <vector>

using uint = unsigned int;

void print_partition_ints(const std::vector<int>& as, const uint q, const uint n) {
    for (uint i = 0; i < n; ++i) {
        if (i != 0) std::cout << " ";
        if (i == q) std::cout << "[" << as[i] << "]";
        else std::cout << as[i];
    }
    std::cout << "\n";
}

uint partition(std::vector<int>& as, const uint first, const uint last) {
    uint less = first;
    for (uint i = first; i < last; ++i) {
        if (as[i] <= as[last]) {
            as[less] ^= as[i];
            as[i] ^= as[less];
            as[less] ^= as[i];
            ++less;
        }
    }
    as[less] ^= as[last];
    as[last] ^= as[less];
    as[less] ^= as[last];
    return less;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    uint n;
    std::cin >> n;
    std::vector<int> as(n);
    for (uint i = 0; i < n; ++i) {
        std::cin >> as[i];
    }
    uint q = partition(as, 0, n - 1);
    print_partition_ints(as, q, n);
}