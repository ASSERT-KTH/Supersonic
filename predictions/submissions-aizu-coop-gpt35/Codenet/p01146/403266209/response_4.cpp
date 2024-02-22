#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

#define INF std::numeric_limits<int>::max()

int main() {
    int n, m, l, k, a, h, t1, t2, t3;
    while (std::cin >> n >> m >> l >> k >> a >> h, n) {
        std::vector<bool> rei(n, false);
        rei[a] = true;
        rei[h] = true;
        for (int i = 0; i < l; i++) {
            int re;
            std::cin >> re;
            rei[re] = true;
        }

        std::vector<int> b(n * n, INF);
        for (int i = 0; i < k; i++) {
            std::cin >> t1 >> t2 >> t3;
            b[t1 * n + t2] = b[t2 * n + t1] = t3;
        }

        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    b[i * n + j] = std::min(b[i * n + j], b[i * n + o] + b[o * n + j]);
                }
            }
        }

        std::vector<int> x(n * n, INF);
        for (int i = 0; i < n; i++) {
            if (rei[i]) {
                for (int j = 0; j < n; j++) {
                    if (rei[j] && b[i * n + j] <= m) {
                        x[i * n + j] = b[i * n + j];
                    }
                }
            }
        }

        for (int o = 0; o < n; o++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    x[i * n + j] = std::min(x[i * n + j], x[i * n + o] + x[o * n + j]);
                }
            }
        }

        if (x[a * n + h] >= INF)
            std::cout << "Help!" << std::endl;
        else if (x[a * n + h] < m)
            std::cout << x[a * n + h] << std::endl;
        else
            std::cout << x[a * n + h] * 2 - m << std::endl;
    }
}