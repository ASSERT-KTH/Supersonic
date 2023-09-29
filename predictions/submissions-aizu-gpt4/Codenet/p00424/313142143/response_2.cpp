#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::unordered_map<char, int> d;
    char a, b;
    while (std::cin >> n && n) {
        d.clear();
        while (n--) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        std::cin >> n;
        while (n--) {
            std::cin >> a;
            std::cout << static_cast<char>(a + d[a]);
        }
        std::cout << '\n';
    }
}