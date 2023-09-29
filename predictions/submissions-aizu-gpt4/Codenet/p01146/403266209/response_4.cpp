#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define INF 1e9
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l, k, a, h;
    while (cin >> n >> m >> l >> k >> a >> h, n) {
        vector<int> rei(n, 0);
        rei[a] = rei[h] = 1;
        vector<vector<int>> b(n, vector<int>(n, INF)), x(n, vector<int>(n, INF));
        int re, t1, t2, t3;
        for (int i = 0; i < l; i++) {
            cin >> re;
            rei[re] = 1;
        }
        for (int i = 0; i < k; i++) {
            cin >> t1 >> t2 >> t3;
            b[t1][t2] = b[t2][t1] = t3;
        }
        for (int o = 0; o < n; o++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    b[i][j] = min(b[i][j], b[i][o] + b[o][j]);
        for (int i = 0; i < n; i++)
            if (rei[i])
                for (int j = 0; j < n; j++)
                    if (rei[j] && b[i][j] <= m)
                        x[i][j] = b[i][j];
        for (int o = 0; o < n; o++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    x[i][j] = min(x[i][j], x[i][o] + x[o][j]);
        if (x[a][h] >= INF)
            cout << "Help!" << '\n';
        else if (x[a][h] < m)
            cout << x[a][h] << '\n';
        else
            cout << x[a][h] * 2 - m << '\n';
    }
    return 0;
}