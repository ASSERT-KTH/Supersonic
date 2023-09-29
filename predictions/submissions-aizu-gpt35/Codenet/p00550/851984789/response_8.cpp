#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+5;
int n, m, q, c, dist[MAXN], T[MAXN], cnt, U[MAXN];
vector<pair<int, int>> x[MAXN], y[MAXN];
bool used[MAXN];
int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0, a, b; i < m; i++) {
        scanf("%d%d", &a, &b);
        x[a].emplace_back(b, i);
        x[b].emplace_back(a, i);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    queue<int> Q;
    Q.push(1);
    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop();
        for (pair<int, int> i : x[a1]) {
            if (dist[i.first] > dist[a1] + 1) {
                dist[i.first] = dist[a1] + 1;
                Q.push(i.first);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (pair<int, int> j : x[i]) {
            if (dist[i] < dist[j.first]) {
                y[i].emplace_back(j);
                T[j.first]++;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &c);
        c--;
        queue<pair<int, int>> Q1;
        int ss = -1;
        if (dist[x[c][0].first] < dist[x[c][1].first])
            ss = x[c][1].first;
        else if (dist[x[c][0].first] > dist[x[c][1].first])
            ss = x[c][0].first;
        if (ss >= 1 && !U[ss] && !used[c]) {
            Q1.emplace(ss, c);
            while (!Q1.empty()) {
                int a1 = Q1.front().first, a2 = Q1.front().second;
                Q1.pop();
                if (U[a1] || used[a2])
                    continue;
                T[a1]--;
                used[a2] = true;
                if (T[a1] != 0)
                    continue;
                cnt++;
                U[a1] = 1;
                for (pair<int, int> j : y[a1]) {
                    if (!U[j.first])
                        Q1.push(j);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}