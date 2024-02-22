#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

int n, m, k;
int x[100001], y[100001];
unordered_map<ll, int> g;
int cost[100001];

int bfs(int start_x, int start_y, int end_x, int end_y) {
    queue<int> que;
    queue<int> que2;
    bool flag = false;
    memset(cost, -1, sizeof(cost));
    ll val = (ll)start_y * n + start_x;
    if (g.find(val) != g.end()) {
        que.push(g[val]);
        cost[g[val]] = 0;
    }
    while (que.size()) {
        int q = que.front();
        que.pop();
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int nc = 0;
                if (abs(i) > 1 || abs(j) > 1)
                    nc = 1;
                int nx = j + x[q], ny = i + y[q];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;
                if (nx == end_x && ny == end_y)
                    continue;
                ll nval = (ll)ny * n + nx;
                if (g.find(nval) != g.end()) {
                    if (cost[g[nval]] == -1) {
                        cost[g[nval]] = nc;
                        if (nc == 0)
                            que.push(g[nval]);
                        if (nc == 1)
                            que2.push(g[nval]);
                    } else if (cost[g[nval]] == 1 && nc == 0) {
                        cost[g[nval]] = 0;
                        que.push(g[nval]);
                    }
                }
            }
        }
    }
    if (flag)
        return 1;
    while (que2.size()) {
        int q = que2.front();
        que2.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nc = 0;
                int nx = j + x[q], ny = i + y[q];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    return 1;
                ll nval = (ll)ny * n + nx;
                if (g.find(nval) != g.end()) {
                    if (cost[g[nval]] == -1) {
                        cost[g[nval]] = 1;
                        que2.push(g[nval]);
                    }
                }
            }
        }
    }
    return 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i];
        g[(ll)y[i] * n + x[i]] = i;
    }
    int res = 2;
    res = min(res, bfs(1, 0, n - 1, m - 1));
    res = min(res, bfs(0, 1, n - 1, m - 1));
    res = min(res, bfs(0, m - 2, n - 1, m - 1));
    res = min(res, bfs(n - 1, 0, n - 1, m - 1));
    cout << res << endl;
    return 0;
}