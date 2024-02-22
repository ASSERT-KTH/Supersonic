#include <cstdio>
#include <cstring>

#define MOD 1000000007LL

typedef long long ll;

int n, m, k;
int x[100001], y[100001];
int g[1000][1000];
int cost[100001];

int bfs(int sx, int sy) {
    int dx[] = {-2, -1, 0, 1, 2};
    int dy[] = {-2, -1, 0, 1, 2};
    int dxSize = sizeof(dx) / sizeof(dx[0]);
    int dySize = sizeof(dy) / sizeof(dy[0]);

    int res = 2;
    bool flag = false;

    memset(cost, -1, sizeof(cost));
    std::queue<int> que;
    que.push(g[sy][sx]);
    cost[g[sy][sx]] = 0;

    while (!que.empty()) {
        int q = que.front();
        que.pop();

        for (int i = 0; i < dxSize; i++) {
            for (int j = 0; j < dySize; j++) {
                int nc = 0;