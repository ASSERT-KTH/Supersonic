#include <iostream>
#include <algorithm>

using namespace std;

constexpr int INF = 100000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    int *a = new int[n + 1];
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
        dp[i] = new int[256];

    while (cin >> n >> m, n) {
        int b[m];
        for (int i = 0; i < m; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) cin >> a[i + 1];
        for (int i = 0; i <= n; ++i) 
            for (int j = 0; j < 256; ++j) 
                dp[i][j] = INF;
        dp[0][128] = 1;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 256; ++j) 
                if (dp[i][j] != INF)
                    for (int k = 0; k < m; ++k) {
                        int p = j + b[k];
                        if (p > 255)
                            p = 255;
                        else if (p < 0)
                            p = 0;
                        dp[i + 1][p] = min(dp[i + 1][p], dp[i][j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
        
        int p = INF;
        for (int i = 0; i < 256; ++i) 
            if (dp[n][i] != INF) 
                p = min(p, dp[n][i]);
        
        cout << p - 1 << '\n';
    }
    delete[] a;
    for(int i = 0; i <= n; ++i)
        delete[] dp[i];
    delete[] dp;

    return 0;
}