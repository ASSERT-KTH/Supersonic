#include <iostream>

int main() {
    int x, y, s;
    while (std::cin >> x >> y >> s && (x || y || s)) {
        int maxi = 0;
        for (int a = 1; a < s; a++) {
            int b = (s - a * (100 + x) / 100) * 100 / (100 + x);
            if (a * (100 + x) + b * (100 + x) == s * 100 && b != 0) {
                int revenue = a * (100 + y) + b * (100 + y);
                maxi = std::max(maxi, revenue);
            }
        }
        std::cout << maxi << std::endl;
    }
    return 0;
}