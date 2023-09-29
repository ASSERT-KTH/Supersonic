#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int num, cap, price;

    while (std::cin >> num >> cap && (num || cap)) {
        std::vector<int> vegetables(num);
        for (int& vegetable : vegetables) {
            std::cin >> vegetable;
        }
        std::sort(vegetables.rbegin(), vegetables.rend());
        int sum = 0;
        for (int i = 0; i < num - num / cap; ++i) {
            sum += vegetables[i];
        }
        std::cout << sum << '\n';
    }
    return 0;
}