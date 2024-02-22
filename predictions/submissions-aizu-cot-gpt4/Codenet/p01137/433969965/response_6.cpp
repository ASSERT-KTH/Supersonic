#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;

const int inf = 1000000000;

int main() {
    int e;
    while (std::cin >> e, e) {
        int ans = inf;
        for (int z = 0; z * z * z <= e; ++z) {
            int left = 0, right = e;
            while (left <= right) {
                int y = (left + right) / 2;
                int x = e - (y * y + z * z * z);
                if (x < 0) {
                    right = y - 1;
                } else {
                    ans = std::min(ans, x + y + z);
                    left = y + 1;
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}