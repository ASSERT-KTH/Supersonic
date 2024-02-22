#include <iostream>
#include <vector>
#include <limits>

int main() {
    int n, m, l, k, a, h;
    while (std::cin >> n >> m >> l >> k >> a >> h, n) {
        std::vector<int> rei(l);
        for (int i = 0; i < l; i++) {
            std::cin >> rei[i];
        }

        std::vector<std::vector<int>> b(n, std::vector<int>(n, std::numeric_limits<int>::max()));
        for (int i = 0; i < k; i++) {
            int t1, t2, t3;
            std::cin >> t1 >> t2 >> t3;
            b[t1][t2] = b[t2][t1] = t3;
        }

        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i][j] = std::min(b[i][j], b[i][o] + b[o][j]);
                }
            }
        }

        std::vector<std::vector<int>> x(n, std::vector<int>(n, std::numeric_limits<int>::max()));
        for (int i = 0; i < n; i++) {
            if (i == a || i == h) {
                for (int j = 0; j < n; j++) {
                    if (j == a || j == h) {
                        if (b[i][j] <= m) {
                            x[i][j] = b[i][j];
                        }
                    }
                }
            }
        }

        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    x[i][j] = std::min(x[i][j], x[i][o] + x[o][j]);
                }
            }
        }

        if (x[a][h] == std::numeric_limits<int>::max()) {
            std::cout << "Help!" << std::endl;
        } else if (x[a][h] < m) {
            std::cout << x[a][h] << std::endl;
        } else {
            std::cout << 2 * x[a][h] - m << std::endl;
        }
    }
    return 0;
}