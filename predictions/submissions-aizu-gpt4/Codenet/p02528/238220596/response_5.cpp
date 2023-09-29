#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::make_heap(a.begin(), a.end(), std::greater<int>());
    std::sort_heap(a.begin(), a.end(), std::greater<int>());

    for(const auto& val : a) {
        std::cout << val << ' ';
    }

    std::cout << '\n';

    return 0;
}