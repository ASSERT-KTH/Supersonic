#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_map>
#define MOD 1000000007LL
typedef long long ll;
typedef std::pair<int, int> P;
int n, m, k;
int x[100001], y[100001];
std::unordered_map<ll, int> g;
int cost[100001];
int bfs(int start, int end, int increment) {
    std::queue<int> que, que2;
    bool flag = false;
    memset(cost, -1, sizeof(cost));
    for (int i = start; i != end; i += increment) {
        ll val = (ll)i * n;
        auto it = g.find(val);
        if (it != g.end()) {
            que.push(it->second);
            cost[it->second] = 0;
        }
    }
    while (!que.empty()) {
        int q = que.front(); que.pop();
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                int nc = 1;
                if (abs(i) <= 1 && abs(j) <= 1) nc = 0;
                int nx = j + x[q], ny = i + y[q];
                if (nx < 0 || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1 || ny < 0 || ny >= m) continue;
                if (nx >= n) {
                    if (nc == 0) return 0;
                    if (nc == 1) flag = true;
                    continue;
                }
                ll nval = (ll)ny * n + nx;
                auto it = g.find(nval);
                if (it != g.end()) {
                    if (cost[it->second] == -1) {
                        cost[it->second] = nc;
                        (nc == 0 ? que : que2).push(it->second);
                    } else if (cost[it->second] == 1 && nc == 0) {
                        cost[it->second] = 0;
                        que.push(it->second);
                    }
                }
            }
        }
    }
    if (flag) return 1;
    while (!que2.empty()) {
        int q = que2.front(); que2.pop();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = j + x[q], ny = i + y[q];
                if (nx < 0 || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1 || ny < 0 || ny >= m) continue;
                if (nx >= n) return 1;
                ll nval = (ll)ny * n + nx;
                auto it = g.find(nval);
                if (it != g.end() && cost[it->second] == -1) {
                    cost[it->second] = 1;
                    que2.push(it->second);
                }
            }
        }
    }
    return 2;
}
int main(void) {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &x[i], &y[i]);
        g[(ll)y[i] * n + x[i]] = i;
    }
    int res = std::min({bfs(1, m, 1), bfs(1, n, 1), bfs(n * (m - 1), n * m, 1), bfs(n - 1, n * (m - 1), n)});
    printf("%d\n", res);
    return 0;
}