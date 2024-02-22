#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    char s[201];
    int m, h, t;
    while (std::cin >> s >> m && s[0] != '-') {
        int a = strlen(s);
        std::vector<int> shifts(m);
        for (int i = 0; i < m; ++i) {
          std::cin >> h;
          t += h;
        }
        t %= a;
        for (int i = 0; i < a; ++i)
            std::cout << s[(t + i) % a];
        std::cout << '\n';
    }
    return 0;
}