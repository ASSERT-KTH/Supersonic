#include <iostream>

int main() {
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> a >> b;
    int ab = a * b;
    std::cout << ab << " " << (a + b) << " " << std::endl;
    return 0;
}