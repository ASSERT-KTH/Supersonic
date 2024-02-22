#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

#define MOD 1000000007LL
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n, m, k;
int x[100001], y[100001];
bool g[100001][100001];
int cost[100001];

#define isInGrid(nx, ny) (nx >= 0 && nx < n && ny >= 0 && ny < m)

#define isCorner(nx, ny) (nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1)

int bfs(int sx, int sy, int ex, int ey, bool isVertical) {
  queue<int> que;
  bool flag = false;
  memset(cost, -1, sizeof(cost));

  for (int i = sx; i <= ex; i++) {
    int nx = isVertical ? i : sy;
    int ny = isVertical ? sy : i;
    if (g[nx][ny]) {
      que.push(g[nx][ny]);
      cost[g[nx][ny]] = 0;
    }
  }

  while (que.size()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = (abs(i) > 1 || abs(j) > 1) ? 1 : 0;
        int nx = j + x[q], ny = i + y[q];

        if (!isInGrid(nx, ny) || isCorner(nx, ny)) continue;

        if (g[nx][ny]) {
          if (cost[g[nx][ny]] == -1) {
            cost[g[nx][ny]] = nc;
            if (nc == 0) que.push(g[nx][ny]);
            else que2.push(g[nx][ny]);
          } else if (cost[g[nx][ny]] == 1 && nc == 0) {
            cost[g[nx][ny]] = 0;
            que.push(g[nx][ny]);
          }
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
    g[x[i]][y[i]] = true;
  }
  
  int res = 2;
  res = min(res, bfs(1, 0, m - 1, 0, true));
  res = min(res, bfs(1, 0, n - 1, 0, false));
  res = min(res, bfs(0, 0, n - 2, m - 1, true));
  res = min(res, bfs(0, 0, m - 2, n - 1, false));

  printf("%d\n", res);
  return 0;
}