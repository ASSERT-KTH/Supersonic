#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<long long> a;
    a.reserve(n);
    long long min = std::numeric_limits<long long>::max();
    long long max = std::numeric_limits<long long>::min();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        long long ii;
        std::cin >> ii;
        a.push_back(ii);
        if(ii < min) min = ii;
        if(ii > max) max = ii;
        sum += ii;
    }
    std::cout << min << " " << max << " " << sum << std::endl;
    return 0;
}