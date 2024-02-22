#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n); // Reserve space in vector

    long long min_val = std::numeric_limits<long long>::max();
    long long max_val = std::numeric_limits<long long>::min();
    long long sum = 0;

    // Read input and compute min, max, and sum in one pass
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        min_val = std::min(min_val, a[i]);
        max_val = std::max(max_val, a[i]);
        sum += a[i];
    }

    std::cout << min_val << " " << max_val << " " << sum << std::endl;
}