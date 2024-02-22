#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, k, a, h, t1, t2, t3;
    while (cin >> n >> m >> l >> k >> a >> h, n) {
        vector<int> rei(n, 0);
        rei[a] = rei[h] = 1;
        int b[n][n], re, x[n][n];
        r(i, n) r(j, n) x[i][j] = b[i][j] = INF;
        r(i, l) cin >> re, rei[re] = 1;
        r(i, k) cin >> t1 >> t2 >> t3, b[t1][t2] = b[t2][t1] = t3;
        r(o, n) r(i, n) r(j, n) b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
        r(i, n) if (rei[i]) r(j, n) if (rei[j]) if (b[i][j] <= m)
            x[i][j] = b[i][j];
        r(o, n) r(i, n) r(j, n) x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        if (x[a][h] >= INF)
            cout << "Help!" << "\n";
        else if (x[a][h] < m)
            cout << x[a][h] << "\n";
        else
            cout << x[a][h] * 2 - m << "\n";
    }
    return 0;
}