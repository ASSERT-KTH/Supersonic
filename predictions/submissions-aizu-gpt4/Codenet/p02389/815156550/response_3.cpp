#include <iostream>

int main() {
    int a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> a >> b;
    std::cout << a * b << ' ' << (a + b) << " " << '\n';
}