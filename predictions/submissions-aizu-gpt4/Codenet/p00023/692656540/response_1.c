#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        double xa, ya, ra, xb, yb, rb;
        std::cin >> xa >> ya >> ra >> xb >> yb >> rb;
        double d = std::hypot(xb - xa, yb - ya);
        double sum = ra + rb;
        double diff1 = std::abs(ra - rb);
        double diff2 = std::abs(rb - ra);
        if (d > sum) {
            ans[i] = 0;
        } else if (diff1 > d) {
            ans[i] = 2;
        } else if (diff2 > d) {
            ans[i] = -2;
        } else {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << '\n';
    }
    return 0;
}