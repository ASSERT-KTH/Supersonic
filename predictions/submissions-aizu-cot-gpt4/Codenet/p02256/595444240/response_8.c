#include <iostream>
#include <algorithm>

int main() {
    int a, b;
    std::cin >> a >> b;
    while (b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    std::cout << a << std::endl;
    return 0;
}