#include <iostream>
#include <cmath>

int main() {
    static constexpr double PI = 3.14159265358979323846;
    double r;
    std::cin >> r;
    double rSquare = r * r;
    std::cout << PI * rSquare << " " << 2 * PI * r << '\n';
    return 0;
}