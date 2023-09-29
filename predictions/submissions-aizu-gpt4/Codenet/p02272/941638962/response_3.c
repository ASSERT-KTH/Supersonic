#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t n;
    std::cin >> n;

    std::vector<int> values(n);
    for(auto &value : values)
        std::cin >> value;

    std::sort(values.begin(), values.end());

    for(size_t i = 0; i < n; ++i) {
        if(i != 0) std::cout << ' ';
        std::cout << values[i];
    }

    return 0;
}