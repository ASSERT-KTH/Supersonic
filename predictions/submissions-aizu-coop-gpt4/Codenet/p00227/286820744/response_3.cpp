#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false); // Speedup I/O
    std::cin >> std::noskipws; // Skip whitespaces
    int num, cap, price;

    while (std::cin >> num >> cap) {
        if (num == 0 && cap == 0) {
            break;
        }

        std::vector<int> vegetables;
        vegetables.reserve(num); // Pre-allocate memory

        for (int i = 0; i < num; ++i) { // Use prefix increment
            std::cin >> price;
            vegetables.push_back(price);
        }

        sort(vegetables.begin(), vegetables.end(), std::greater<int>());

        int sum = 0;
        for (int i = 0; i < num; ++i) { // Use prefix increment
            if ((i + 1) % cap != 0) {
                sum += vegetables[i]; // Use [] instead of at()
            }
        }

        std::cout << sum << "\n"; // Use "\n" instead of std::endl to avoid unnecessary flush
    }

    return 0;
}