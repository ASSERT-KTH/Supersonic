#include <iostream>
#include <cmath>

int main() {
    int e;
    while (std::cin >> e, e) {
        int minSteps = 1000000;
        for (int z = 100; z >= 0; --z) {
            int val = z * z * z;
            if (val > e)
                continue;
            int y = std::sqrt(e - val);
            int val2 = val + y * y;
            if (val2 > e)
                continue;
            minSteps = (e - val2) + y + z;
        }
        std::cout << minSteps << std::endl;
    }
    return EXIT_SUCCESS;
}