#include <iostream>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    while(std::cin >> n && n != 0) {
        std::unordered_map<char, int> d;
        char a, b;
        while(n--) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        std::cin >> n;
        while(n--) {
            std::cin >> a;
            std::cout << char(a + d[a]);
        }
        std::cout << "\n";
    }
}