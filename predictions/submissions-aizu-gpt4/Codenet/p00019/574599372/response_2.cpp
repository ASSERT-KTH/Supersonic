#include <iostream>

int main() {
    unsigned long long a = 1;
    unsigned int n;
    std::cin >> n;
    for (unsigned int i = 2; i <= n; ++i) {
        a *= i;
    }
    std::cout << a << '\n';
    return 0;
}