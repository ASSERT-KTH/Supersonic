#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    int m, h, t = 0;
    while (std::getline(std::cin, s) && s[0] != '-') {
        std::cin >> m;
        for (int i = 0; i < m; i++) {
            std::cin >> h;
            t += h;
            std::rotate(s.begin(), s.begin() + t, s.end());
        }
        std::cout << s << std::endl;
    }
    return 0;
}