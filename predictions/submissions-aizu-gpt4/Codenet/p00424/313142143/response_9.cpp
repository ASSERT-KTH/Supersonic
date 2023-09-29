#include <iostream>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    char a, b;
    int n;
    while (std::cin >> n && n) {
        std::unordered_map<char, int> d;
        d.reserve(256);
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