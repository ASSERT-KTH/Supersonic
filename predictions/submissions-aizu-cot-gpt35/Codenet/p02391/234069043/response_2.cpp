#include <iostream>

int main() {
    constexpr double pai = 3.141592653589;
    int a, b;
    std::cin >> a >> b;

    std::cout << (a > b ? "a > b" : (a < b ? "a < b" : "a == b")) << std::endl;

    return 0;
}