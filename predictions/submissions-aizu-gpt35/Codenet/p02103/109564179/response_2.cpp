#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
int n, m, k;
int x[100001], y[100001];
map<ll, int> g;
int cost[100001];
int bfs(int sx, int sy, int dx, int dy) {
  queue<int> que;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  if (g.count((ll)sy * n + sx)) {
    que.push(g[(ll)sy * n + sx]);
    cost[g[(ll)sy * n + sx]] = 0;
  }
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx == dx && ny == dy) {
          return cost[q] + nc;
        }
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        } else if (g.count((ll)ny * n + nx)) {
          int idx = g[(ll)ny * n + nx];
          if (cost[idx] == -1) {
            cost[idx] = cost[q] + nc;
            que.push(idx);
          } else if (cost[idx] == cost[q] + 1 && nc == 0) {
            cost[idx] = cost[q];
            que.push(idx);
          }
        }
      }
    }
  }
  return flag ? 1 : 2;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    g[(ll)y[i] * n + x[i]] = i;
  }
  int res = 2;
  res = min(res, bfs(0, 0, n - 1, m - 1));
  res = min(res, bfs(0, 0, n - 1, m - 1));
  res = min(res, bfs(0, 0, n - 1, m - 1));
  res = min(res, bfs(0, 0, n - 1, m - 1));
  printf("%d\n", res);
  return 0;
}