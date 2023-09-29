#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <limits>

constexpr int INF = std::numeric_limits<int>::max();
constexpr int MAXN = 6000;

std::vector<int> pass[MAXN];
int n, k;
int c[MAXN];
int r[MAXN];
int d[MAXN];

void bfs(int v) {
    std::queue<std::pair<int, int>> que;
    que.push(std::make_pair(v, r[v]));
    while (!que.empty()) {
        int u = que.front().first;
        int res = que.front().second;
        que.pop();
        for (int i = 0; i < pass[u].size(); i++) {
            int to = pass[u][i];
            if (d[u] + c[u] < d[to]) {
                d[to] = d[u] + c[u];
                if (res > 0) {
                    que.push(std::make_pair(to, res - 1));
                }
            }
        }
    }
}

int dijk(int s, int g) {
    std::fill(d, d + MAXN, INF);
    d[s] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> que;
    que.push(std::make_pair(0, s));
    while (!que.empty()) {
        int v = que.top().second;
        que.pop();
        bfs(v);
        for (int i = 0; i < pass[v].size(); i++) {
            int to = pass[v][i];
            if (d[v] + c[v] < d[to]) {
                d[to] = d[v] + c[v];
                que.push(std::make_pair(d[to], to));
            }
        }
    }
    return d[g];
}

int main() {
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) std::cin >> c[i] >> r[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        std::cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    std::cout << dijk(0, n - 1) << std::endl;

    return 0;
}