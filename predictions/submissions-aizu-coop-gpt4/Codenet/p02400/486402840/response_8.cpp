#include <iostream>
#include <cmath>

int main() {
    double r;
    std::cin >> r;
    const double pi = M_PI;
    std::cout << std::fixed;
    std::cout.precision(8);
    std::cout << r * r * pi << std::endl << pi * (r + r) << std::endl;
    return 0;
}