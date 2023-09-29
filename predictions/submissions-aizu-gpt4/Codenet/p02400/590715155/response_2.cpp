#include <iostream>

int main() {
    constexpr double PI = 3.141592653589;
    double r;
    
    std::cin >> r;
    
    const auto result1 = PI * r * r;
    const auto result2 = 2 * PI * r;
    
    std::cout << result1 << ' ' << result2 << '\n';
    return 0;
}