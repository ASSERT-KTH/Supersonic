#include <iostream>
#include <cmath>
#include <algorithm>

int main(void) {
    int e;
    while (std::cin >> e, e) {
        int m = e;
        int val, val2;
        for (int z = 100; z >= 0; --z) {
            val = z * z * z;
            for (int y = std::sqrt(e - val); y >= 0; --y) {
                val2 = val + y * y;
                m = std::min(m, (e - val2) + y + z);
            }
        }
        std::cout << m << std::endl;
    }
    return EXIT_SUCCESS;
}