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
map<ll, int> g;
int cost[100001];

int bfs(int a, int b, int c, int d) {
  queue<int> que, que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = a; i <= b; i++) {
    ll val = (ll)i * n + c;
    if (g.find(val) != g.end()) {
      que.push(g[val]);
      cost[g[val]] = 0;
    }
  }
  while (que.size()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = abs(i) > 1 || abs(j) > 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx < d || nx >= n || ny < d || ny >= m)
          continue;
        if ((nx == 0 && ny == 0) || (nx == n - 1 && ny == m - 1))
          continue;
        if ((nx == n || ny == m || nx < 0 || ny < 0) && nc == 1)
          flag = true;
        ll nval = (ll)ny * n + nx;
        if (g.find(nval) != g.end() && cost[g[nval]] == -1) {
          cost[g[nval]] = nc;
          if (nc == 0)
            que.push(g[nval]);
          else
            que2.push(g[nval]);
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
        int nx = j + x[q], ny = i + y[q];
        if (nx < d || nx >= n || ny < d || ny >= m)
          continue;
        if ((nx == 0 && ny == 0) || (nx == n - 1 && ny == m - 1))
          continue;
        ll nval = (ll)ny * n + nx;
        if (g.find(nval) != g.end() && cost[g[nval]] == -1) {
          cost[g[nval]] = 1;
          que2.push(g[nval]);
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
  int res = 2;
  res = min(res, bfs(1, m - 1, 0, 0));
  res = min(res, bfs(1, n - 1, 0, 0));
  res = min(res, bfs(0, n - 2, m - 1, 0));
  res = min(res, bfs(0, m - 2, n - 1, 0));
  printf("%d\n", res);
  return 0;
}