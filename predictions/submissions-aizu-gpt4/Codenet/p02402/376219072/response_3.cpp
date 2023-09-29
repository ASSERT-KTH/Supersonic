#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (long long &i : a) {
        std::cin >> i;
    }

    auto [min, max] = std::minmax_element(a.begin(), a.end());
    long long sum = std::accumulate(a.begin(), a.end(), 0LL);
    
    std::cout << *min << " " << *max << " " << sum << std::endl;

    return 0;
}