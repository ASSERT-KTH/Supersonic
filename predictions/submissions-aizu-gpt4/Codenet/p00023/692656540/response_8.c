#include <iostream>
#include <cmath>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans(n);
    double xa, ya, ra, xb, yb, rb, dist, sumR, diffR1, diffR2;

    for (int k = 0; k < n; k++) {
        std::cin >> xa >> ya >> ra >> xb >> yb >> rb;
        dist = std::hypot(xb - xa, yb - ya);
        sumR = ra + rb;
        diffR1 = std::abs(ra - rb);
        diffR2 = std::abs(rb - ra);
        
        if (dist > sumR) {
            ans[k] = 0;
        } else if (diffR1 > dist) {
            ans[k] = 2;
        } else if (diffR2 > dist) {
            ans[k] = -2;
        } else {
            ans[k] = 1;
        }
    }
    for (int k = 0; k < n; k++) {
        std::cout << ans[k] << "\n";
    }
    return 0;
}