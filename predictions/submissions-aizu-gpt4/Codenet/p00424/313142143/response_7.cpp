#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    char a, b;
    while(std::cin >> a) {
        std::vector<int> d(256, 0);
        for (int n = a; n--; d[a] = b - a) {
            std::cin >> a >> b;
        }
        std::cin >> a;
        for (int n = a; n--; putchar(a + d[a])) {
            std::cin >> a;
        }
    }
    return 0;
}