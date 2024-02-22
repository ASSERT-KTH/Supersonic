#include <iostream>
#include <algorithm>

int main() {
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    int minValue = std::min(std::min(a, b), std::min(c, d));
    int maxValue = std::max(e, f);

    int ans = a + b + c + d - minValue + maxValue;
    std::cout << ans << std::endl;

    return 0;
}