#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<long long> a(n);

    long long min_val = 1e18;
    long long max_val = -1e18;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        min_val = std::min(min_val, a[i]);
        max_val = std::max(max_val, a[i]);
        sum += a[i];
    }

    std::cout << min_val << " " << max_val << " " << sum << std::endl;

    return 0;
}