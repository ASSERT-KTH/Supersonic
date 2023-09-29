#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, a;
    while (std::cin >> n >> m >> a && (n || m || a)) {
        std::vector<std::vector<int>> amida(n + 1, std::vector<int>(m + 1));
        for (int i = 0; i < m; ++i) {
            int h, p, q;
            std::cin >> h >> p >> q;
            amida[p][h] = 1;
        }
        for (int j = m; j > 0; --j) {
            if (amida[a][j])
                ++a;
            else if (a > 1 && amida[a - 1][j])
                --a;
        }
        std::cout << a << '\n';
    }

    return 0;
}