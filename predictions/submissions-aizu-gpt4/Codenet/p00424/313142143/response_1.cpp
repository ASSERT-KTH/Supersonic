#include <iostream>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    while (std::cin >> n && n != 0) {
        std::unordered_map<char, int> d;
        char a, b;
        for (; n--; d[a] = b - a)
            std::cin >> a >> b;
        std::cin >> n;
        for (; n--; std::cout.put(a + d[a]))
            std::cin >> a;
        std::cout << '\n';
    }
    return 0;
}