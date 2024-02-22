#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
vector<int> x[110000], y[110000], weight_x[110000], weight_y[110000];
bool used[210000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        x[a[i]].push_back(b[i]);
        x[b[i]].push_back(a[i]);
        weight_x[a[i]].push_back(i);
        weight_x[b[i]].push_back(i);
    }
    fill_n(dist, n + 1, 999999);
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop();
        for (int i = 0; i < x[a1].size(); ++i) {
            if (dist[x[a1][i]] > dist[a1] + 1) {
                dist[x[a1][i]] = dist[a1] + 1;
                Q.push(x[a1][i]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < x[i].size(); ++j) {
            if (dist[i] < dist[x[i][j]]) {
                y[i].push_back(x[i][j]);
                weight_y[i].push_back(weight_x[i][j]);
                T[x[i][j]]++;
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        cin >> c; c--;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && U[ss] == 0 && used[c] == false) {
            Q.push(ss);
            while (!Q.empty()) {
                int a1 = Q.front(), a2 = weight_y[a1][0];
                Q.pop();
                if (U[a1] == 1 || used[a2] == true)
                    continue;
                T[a1]--;
                used[a2] = true;
                if (T[a1] != 0)
                    continue;
                cnt++;
                U[a1] = 1;
                for (int j : y[a1]) {
                    if (U[j] == 0)
                        Q.push(j);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}