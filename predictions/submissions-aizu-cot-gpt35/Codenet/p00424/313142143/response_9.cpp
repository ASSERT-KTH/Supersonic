#include <iostream>

int main() {
    int n;
    while (std::cin >> n >> n) {
        int d[256] = {};
        char a, b;
        while (n--) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        while (n--) {
            std::cin >> a;
            std::cout << static_cast<char>(a + d[a]);
        }
        std::cout << std::endl;
    }
}