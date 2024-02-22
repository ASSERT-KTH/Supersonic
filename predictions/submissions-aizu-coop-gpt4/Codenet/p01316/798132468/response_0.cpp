#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    const int INF = 100000000;
    int dp[20001][256];
    int n, m;
    while (cin >> n >> m, n) {
        int b[m];
        int a[n + 1];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> a[i + 1];
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < 256; j++)
                dp[i][j] = INF;
        dp[0][128] = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 256; j++)
                if (dp[i][j] != INF)
                    for (int k = 0; k < m; k++) {
                        int p = j + b[k];
                        if (p > 255)
                            p = 255;
                        if (p < 0)
                            p = 0;
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
        int p = INF;
        for (int i = 0; i < 256; i++)
            if (dp[n][i] != INF)
                p = min(p, dp[n][i]);
        cout << p - 1 << endl;
    }
    return 0;
}