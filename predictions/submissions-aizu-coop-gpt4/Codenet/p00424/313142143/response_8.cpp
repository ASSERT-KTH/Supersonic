#include <iostream>
#include <map>
#include <string>

int main() {
    int n;
    while (std::cin >> n && n) {
        std::map<char, int> d;
        while(n--) {
            char a, b;
            std::cin >> a >> b;
            d[a] = b - a;
        }
        std::cin >> n;
        while(n--) {
            char a;
            std::cin >> a;
            putchar(a + d[a]);
        }
        puts("");
    }
}