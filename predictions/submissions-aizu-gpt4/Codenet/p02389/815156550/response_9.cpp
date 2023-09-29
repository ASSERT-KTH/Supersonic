#include <iostream>

int main() {
    int a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> a >> b;
    int product = a * b;
    int perimeter = (a + b) << 1;
    std::cout << product << " " << perimeter << "\n";
    return 0;
}