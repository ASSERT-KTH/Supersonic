#include <iostream>

int main() {
    int n;
    while (std::cin >> n, n) {
        int b[2][100100], f[2][100100];
        bool v[100100] = {false};

        for (int i = 0; i < n; i++) {
            std::cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
        }

        const int MOD = 10007;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                v[i] = true;
                int num = 1;
                int maxi = f[0][i];
                int now = b[0][i];
                while (!v[now]) {
                    v[now] = true;
                    if (maxi == f[0][now]) {
                        num++;
                    } else if (maxi < f[0][now]) {
                        maxi = f[0][now];
                        num = 1;
                    }
                    if (b[0][now] == i) {
                        break;
                    }
                    now = b[0][now];
                }
                ans = (ans * num) % MOD;
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}