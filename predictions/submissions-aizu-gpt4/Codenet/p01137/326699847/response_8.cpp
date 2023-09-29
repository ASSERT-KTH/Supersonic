#include <iostream>
#include <cmath>
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int e;
    while (std::cin >> e, e) {
        int m = 1000000;
        for (int z = std::cbrt(e); z >= 0; --z) {
            int val = z * z * z;
            for (int y = std::sqrt(e - val); y >= 0; --y) {
                int val2 = val + y * y;
                if (val2 <= e) 
                    m = MIN(m, (e - val2) + y + z);
                else
                    break;
            }
        }
        std::cout << m << '\n';
    }

    return 0;
}