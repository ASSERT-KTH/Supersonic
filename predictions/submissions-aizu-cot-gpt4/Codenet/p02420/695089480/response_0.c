#include <iostream>
#include <string>

int main() {
    int m, h, t, a;
    std::string s;
    while (std::cin >> s >> m, s[0] != '-') {
        a = s.size();
        for (int i = 0, t = 0; i < m; ++i) {
            std::cin >> h;
            t += h;
        }
        for (int i = 0; i < a; ++i) {
            std::cout << s[(t + i) % a];
        }
        std::cout << "\n";
    }
    return 0;
}