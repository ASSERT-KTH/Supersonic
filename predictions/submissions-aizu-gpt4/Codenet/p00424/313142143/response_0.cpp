#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    while(std::cin >> n && n) {
        std::vector<int> d(256, 0);
        char a, b;
        while(n--) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        std::cin >> n;
        while(n--) {
            std::cin >> a;
            std::putchar(a + d[a]);
        }
        std::cout << "\n";
    }
}