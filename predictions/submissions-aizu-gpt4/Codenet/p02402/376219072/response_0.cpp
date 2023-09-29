#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    for (long long& ii : a) {
        std::cin >> ii;
    }
    auto [min, max] = std::minmax_element(a.begin(), a.end());
    std::cout << *min << " " << *max << " " << std::accumulate(a.begin(), a.end(), 0LL) << "\n";
}