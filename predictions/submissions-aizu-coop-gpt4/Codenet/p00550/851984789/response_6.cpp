#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
int x[110000][2], y[110000][2];
bool used[210000];

int main() {
    ios_base::sync_with_stdio(false); // speed up cin and cout
    cin.tie(NULL);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        x[a[i]][0] = b[i];
        x[a[i]][1] = i;
        x[b[i]][0] = a[i];
        x[b[i]][1] = i;
    }

    fill(dist, dist + n + 1, 999999);
    dist[1] = 0;
    int Q[110000], front = 0, back = 0;
    Q[back++] = 1;

    while (front < back) {
        int a1 = Q[front++];
        for (int i = 0; i < 2; i++) {
            if (dist[x[a1][0]] > dist[a1] + 1) {
                dist[x[a1][0]] = dist[a1] + 1;
                Q[back++] = x[a1][0];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (dist[i] < dist[x[i][0]]) {
                y[i][0] = x[i][0];
                y[i][1] = x[i][1];
                T[x[i][0]]++;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> c;
        c--;
        int Q1[110000][2], front1 = 0, back1 = 0;
        int ss = -1;
        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        else if (dist[a[c]] > dist[b[c]])
            ss = a[c];
        if (ss >= 1 && U[ss] == 0 && !used[c]) {
            Q1[back1][0] = ss;
            Q1[back1++][1] = c;
            while (front1 < back1) {
                int a1 = Q1[front1][0], a2 = Q1[front1++][1];
                if (U[a1] || used[a2])
                    continue;
                T[a1]--;
                used[a2] = true;
                if (T[a1] != 0)
                    continue;
                cnt++;
                U[a1] = 1;
                if (U[y[a1][0]] == 0) {
                    Q1[back1][0] = y[a1][0];
                    Q1[back1++][1] = y[a1][1];
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}