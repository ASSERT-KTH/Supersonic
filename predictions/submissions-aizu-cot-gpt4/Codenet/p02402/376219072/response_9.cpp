#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<long long> a(n);  // Allocate memory at once
    long long sum = 0;
    long long minVal = std::numeric_limits<long long>::max();
    long long maxVal = std::numeric_limits<long long>::min();
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
        minVal = std::min(minVal, a[i]);
        maxVal = std::max(maxVal, a[i]);
    }
    
    std::cout << minVal << " " << maxVal << " " << sum << std::endl;
    
    return 0;
}