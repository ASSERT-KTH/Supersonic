#include <cstdio>
#include <cstring>
#include <unordered_map>
#define MOD 1000000007LL

typedef long long ll;
typedef std::pair<int, int> P;

int n, m, k;
int x[100001], y[100001];
std::unordered_map<ll, int> g;
int cost[100001];

int bfs(int start_x, int start_y, int end_x, int end_y) {
  std::queue<int> que;
  bool flag = false;
  std::fill(cost, cost + k, -1);
  
  ll val = (ll)start_y * n + start_x;
  if (g.find(val) != g.end()) {
    que.push(g[val]);
    cost[g[val]] = 0;
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (std::abs(i) > 1 || std::abs(j) > 1)
          nc = 1;

        int nx = j + x[q], ny = i + y[q];

        if (nx == start_x && ny == start_y)
          continue;
        if (nx == end_x && ny == end_y)
          continue;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        }
        else {
          ll nval = (ll)ny * n + nx;
          if (g.find(nval) != g.end()) {
            if (cost[g[nval]] == -1) {
              cost[g[nval]] = nc;
              que.push(g[nval]);
            } else if (cost[g[nval]] == 1 && nc == 0) {
              cost[g[nval]] = 0;
              que.push(g[nval]);
            }
          }
        }
      }
    }
  }

  if (flag)
    return 1;

  return 2;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    g[(ll)y[i] * n + x[i]] = i;
  }

  int res = 2;
  res = std::min(res, bfs(0, 0, n - 1, m - 1));
  res = std::min(res, bfs(0, 0, n - 1, m - 1));
  res = std::min(res, bfs(0, m - 1, n - 1, 0));
  res = std::min(res, bfs(n - 1, 0, 0, m - 1));

  printf("%d\n", res);

  return 0;
}