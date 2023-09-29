#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n) {
        int diff[256] = {};
        for (char a, b; n--; ) {
            std::cin >> a >> b;
            diff[a] = b - a;
        }
        std::cin >> n;
        for (char a; n--; ) {
            std::cin >> a;
            putchar(a + diff[a]);
        }
        putchar('\n');
    }
}