#include <iostream>

int main() {
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> a >> b;
    std::cout << a * b << ' ' << (a + b) << "<< 1" << std::endl;
}