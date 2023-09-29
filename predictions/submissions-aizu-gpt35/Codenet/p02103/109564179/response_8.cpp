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
int bfs() {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = 1; i <= m - 1; i++) {
    ll val = (ll)i * n;
    auto it = g.find(val);
    if (it != g.end()) {
      que.push(it->second);
      cost[it->second] = 0;
    }
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
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (nx == 0 && ny == 0)
          continue;
        if (nx == n - 1 && ny == m - 1)
          continue;
        ll nval = (ll)ny * n + nx;
        auto it = g.find(nval);
        if (it != g.end()) {
          if (cost[it->second] == -1) {
            cost[it->second] = nc;
            if (nc == 0)
              que.push(it->second);
            if (nc == 1)
              que2.push(it->second);
          } else if (cost[it->second] == 1 && nc == 0) {
            cost[it->second] = 0;
            que.push(it->second);
          }
        } else if (nc == 0) {
          return 0;
        } else {
          flag = true;
        }
      }
    }
  }
  if (flag)
    return 1;
  while (!que2.empty()) {
    int q = que2.front();
    que2.pop();
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nc = 0;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (nx == 0 && ny == 0)
          continue;
        if (nx == n - 1 && ny == m - 1)
          continue;
        ll nval = (ll)ny * n + nx;
        auto it = g.find(nval);
        if (it != g.end()) {
          if (cost[it->second] == -1) {
            cost[it->second] = 1;
            que2.push(it->second);
          }
        } else {
          return 1;
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
  res = min(res, bfs());
  swap(n, m);
  for (int i = 0; i < k; i++) {
    swap(x[i], y[i]);
  }
  g.clear();
  for (int i = 0; i < k; i++) {
    g[(ll)y[i] * n + x[i]] = i;
  }
  res = min(res, bfs());
  printf("%d\n", res);
  return 0;
}