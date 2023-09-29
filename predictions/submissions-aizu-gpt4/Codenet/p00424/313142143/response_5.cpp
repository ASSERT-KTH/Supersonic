#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char a, b;
    int n;
    while (std::cin >> n && n) {
        std::unordered_map<char, int> d;
        for (; n--; d[a] = b - a)
            std::cin >> a >> b;
        std::cin >> n;
        for (; n--; std::cout << char(a + d[a]))
            std::cin >> a;
        std::cout << '\n';
    }
}