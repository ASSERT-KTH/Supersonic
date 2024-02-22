#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    int n;
    while(std::cin >> n && n) {
        std::unordered_map<char, int> d;
        char a, b;
        for (; n--; ) {
            std::cin >> a >> b;
            d[a] = b - a;
        }
        std::string s;
        std::cin >> s;
        for (char& a : s) {
            putchar(a + d[a]);
        }
        puts("");
    }
}