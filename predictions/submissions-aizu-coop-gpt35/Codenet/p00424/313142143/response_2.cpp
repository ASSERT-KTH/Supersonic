#include <iostream>
#include <unordered_map>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::unordered_map<char, int> d;
        char a, b;
        while (n--) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        while (std::cin >> n && n--) {
            std::cin >> a;
            std::cout << char(a + d[a]);
        }
        std::cout << '\n';
    }
}