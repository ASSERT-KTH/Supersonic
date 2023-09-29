#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num, cap, price;
    while (std::cin >> num >> cap && (num != 0 || cap != 0)) {
        std::vector<int> vegetables(num);
        for (int& vegetable : vegetables) {
            std::cin >> vegetable;
        }
        sort(vegetables.rbegin(), vegetables.rend());
        int sum = 0;
        for (int i = 0; i < num; ++i) {
            if (i % cap != cap - 1) {
                sum += vegetables[i];
            }
        }
        std::cout << sum << '\n';
    }
    return 0;
}