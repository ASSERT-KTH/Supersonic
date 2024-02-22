#include <iostream>

int main() {
    long long i, n, j[99999], s, a;
    while (true) {
        std::cin >> n;
        if (n == 0)
            break;
        
        s = 0;
        for (i = 0; i < n; ++i) {
            std::cin >> j[i];
            s += j[i];
        }
        
        a = 0;
        for (i = n - 1; i >= 1; --i) {
            std::cin >> j[i];
            a = std::max(a, (i + 1) * s);
            s += j[i];
        }
        
        std::cout << a << std::endl;
    }
    return 0;
}