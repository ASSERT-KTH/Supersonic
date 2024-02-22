#include <iostream>
#include <numeric>
#include <algorithm>

int main() {
    int n, a;
    while (std::cin >> n && n != 0) {
        int s = 0;
        int j[99999];
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            s += a;
            j[i] = a;
        }
        std::sort(j, j + n);
        int max_val = n * s;
        if (n > 1) {
            max_val = std::max(max_val, j[n] + s);
        }
        std::cout << max_val << std::endl;
    }
    return 0;
}