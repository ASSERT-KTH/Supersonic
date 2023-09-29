#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int INF = 1e9 + 7;

int n, m, k;
int x[MAXN], y[MAXN];
unordered_set<long long> g;

struct Point {
    int x, y, cost;
};

bool check_boundary(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int startX, int startY, int endX, int endY) {
    vector<vector<int>> cost(n, vector<int>(m, INF));
    cost[startX][startY] = 0;
    queue<Point> que;
    que.push({startX, startY, 0});

    while (!que.empty()) {
        auto p = que.front();
        que.pop();

        for (int dx = -2; dx <= 2; ++dx) {
            for (int dy = -2; dy <= 2; ++dy) {
                int nx = p.x + dx, ny = p.y + dy;

                if (!check_boundary(nx, ny) || (nx == endX && ny == endY)) {
                    continue;
                }

                int ncost = (abs(dx) > 1 || abs(dy) > 1) ? 1 : 0;
                ncost += p.cost;

                if (cost[nx][ny] <= ncost) {
                    continue;
                }
                cost[nx][ny] = ncost;

                if (g.count(1LL * ny * n + nx)) {
                    que.push({nx, ny, ncost});
                }
            }
        }
    }
    return cost[endX][endY];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x[i] >> y[i];
        g.insert(1LL * y[i] * n + x[i]);
    }

    int res = min({bfs(0, 0, n - 1, m - 1), bfs(0, 0, n - 1, 0), bfs(n - 1, 0, n - 1, m - 1), bfs(n - 1, 0, 0, m - 1)});
    res = res == INF ? 2 : res;
    cout << res << "\n";

    return 0;
}