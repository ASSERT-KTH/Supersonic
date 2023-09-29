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
const int MAXN = 100001;
int n, m, k;
int x[MAXN], y[MAXN];
int cost[MAXN];
int bfs(int sx, int sy) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  if (sx == 0) {
    for (int i = 1; i <= m - 1; i++) {
      if (y[i] == sy) {
        que.push(i);
        cost[i] = 0;
      }
    }
  } else if (sx == n - 1) {
    for (int i = 0; i <= m - 2; i++) {
      if (y[i] == sy) {
        que.push(i);
        cost[i] = 0;
      }
    }
  } else if (sy == 0) {
    for (int i = 1; i <= n - 1; i++) {
      if (x[i] == sx) {
        que.push(i * m);
        cost[i * m] = 0;
      }
    }
  } else if (sy == m - 1) {
    for (int i = 0; i <= n - 2; i++) {
      if (x[i] == sx) {
        que.push(i * m + m - 1);
        cost[i * m + m - 1] = 0;
      }
    }
  } else {
    return 0;
  }
  while (que.size()) {
    int q = que.front();
    que.pop();
    int qx = q / m, qy = q % m;
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + qy, ny = i + qx;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;
        int idx = ny * m + nx;
        if (idx == q)
          continue;
        if (cost[idx] == -1) {
          cost[idx] = nc;
          if (nc == 0)
            que.push(idx);
          if (nc == 1)
            que2.push(idx);
        } else if (cost[idx] == 1 && nc == 0) {
          cost[idx] = 0;
          que.push(idx);
        }
      }
    }
  }
  if (que2.size()) {
    return 1;
  }
  while (que2.size()) {
    int q = que2.front();
    que2.pop();
    int qx = q / m, qy = q % m;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nc = 0;
        int nx = j + qy, ny = i + qx;
        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
          continue;
        int idx = ny * m + nx;
        if (idx == q)
          continue;
        if (cost[idx] == -1) {
          cost[idx] = 1;
          que2.push(idx);
        }
      }
    }
  }
  if (que2.size()) {
    return 1;
  }
  return 2;
}
int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int res = 2;
  res = min(res, bfs(0, 0));
  res = min(res, bfs(n - 1, m - 1));
  res = min(res, bfs(0, m - 1));
  res = min(res, bfs(n - 1, 0));
  printf("%d\n", res);
  return 0;
}
