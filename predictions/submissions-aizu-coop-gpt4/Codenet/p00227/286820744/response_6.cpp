#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int num, cap, price;
    while (std::cin >> num >> cap) {
        if (num == 0 && cap == 0) {
            break;
        }
        std::vector<int> vegetables;
        vegetables.reserve(num);  // Reserve memory upfront
        for (int i = 0; i < num; ++i) {
            std::cin >> price;
            vegetables.push_back(price);
        }
        sort(vegetables.begin(), vegetables.end());  // Sort in ascending order
        int sum = 0;
        for (int i = 0; i < num; ++i) {
            if ((i + 1) % cap != 0) {
                sum += vegetables[i];  // Use operator[] for faster access
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}