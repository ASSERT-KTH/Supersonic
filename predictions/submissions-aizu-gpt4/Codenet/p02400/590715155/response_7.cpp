#include <iostream>
#include <cmath>

int main() {
    constexpr double PI = 3.141592653589;
    double r;
    std::cin >> r;
    double rSquared = r * r;
    std::cout << PI * rSquared << ' ' << 2.0 * PI * r << '\n';
    return 0;
}