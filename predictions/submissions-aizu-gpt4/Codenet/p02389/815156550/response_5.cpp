#include <iostream>

int main() {
    int a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> a >> b;
    std::cout << a * b << " " << (a + b) * 2 << "\n";
    return 0;
}