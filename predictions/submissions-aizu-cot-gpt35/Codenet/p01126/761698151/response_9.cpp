#include <iostream>

int main() {
    int n, m, a;
    while (std::cin >> n >> m >> a && (n != 0 || m != 0 || a != 0)) {
        int amida[1001] = {0};
        for (int i = 0; i < m; i++) {
            int h, p, q;
            std::cin >> h >> p >> q;
            amida[h] = p;
        }
        while (amida[a] != 0) {
            a = amida[a];
        }
        std::cout << a << '\n';
    }
    return 0;
}