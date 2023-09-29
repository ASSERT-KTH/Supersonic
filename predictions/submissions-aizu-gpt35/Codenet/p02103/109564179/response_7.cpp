#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m, k;
int x[100001], y[100001];
int cost[100001];
map<int, map<int, int>> g;
int bfs(int sx, int sy, int ex, int ey) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  if (g.count(sx) && g[sx].count(sy)) {
    que.push(g[sx][sy]);
    cost[g[sx][sy]] = 0;
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
        if (nx == ex && ny == ey)
          return cost[q] + nc;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        }
        if (g.count(nx) && g[nx].count(ny)) {
          if (cost[g[nx][ny]] == -1) {
            cost[g[nx][ny]] = cost[q] + nc;
            if (nc == 0)
              que.push(g[nx][ny]);
            if (nc == 1)
              que2.push(g[nx][ny]);
          } else if (cost[g[nx][ny]] == cost[q] + 1 && nc == 0) {
            cost[g[nx][ny]] = cost[q];
            que.push(g[nx][ny]);
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
        if (nx == ex && ny == ey)
          return cost[q] + 1;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        if (g.count(nx) && g[nx].count(ny)) {
          if (cost[g[nx][ny]] == -1) {
            cost[g[nx][ny]] = cost[q] + 1;
            que2.push(g[nx][ny]);
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
    g[x[i]][y[i]] = i;
  }
  int res = 2;
  res = min(res, bfs(0, 0, n - 1, m - 1));
  res = min(res, bfs(0, 0, n - 1, m));
  res = min(res, bfs(0, 0, n, m - 1));
  res = min(res, bfs(0, 0, n, m));
  printf("%d\n", res);
  return 0;
}