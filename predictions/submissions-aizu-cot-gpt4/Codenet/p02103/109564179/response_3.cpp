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

int bfs(int start, int dx1, int dy1, int dx2, int dy2) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = start; i <= m - 1; i++) {
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
        int abs_i = abs(i);
        int abs_j = abs(j);
        int nc = (abs_i > 1 || abs_j > 1) ? 1 : 0;
        int nx = j + x[q], ny = i + y[q];
        if (nx < dx1 || ny < dy1 || nx >= dx2 || ny >= dy2)
          continue;
        if ((nx == 0 && ny == 0) || (nx == n - 1 && ny == m - 1))
          continue;
        ll nval = (ll)ny * n + nx;
        auto it = g.find(nval);
        if (it != g.end()) {
          if (cost[it->second] == -1) {
            cost[it->second] = nc;
            if (nc == 0)
              que.push(it->second);
            else 
              que2.push(it->second);
          } else if (cost[it->second] == 1 && nc == 0) {
            cost[it->second] = 0;
            que.push(it->second);
          }
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
        if (nx < dx1 || ny < dy1 || nx >= dx2 || ny >= dy2)
          continue;
        if ((nx == 0 && ny == 0) || (nx == n - 1 && ny == m - 1))
          continue;
        ll nval = (ll)ny * n + nx;
        auto it = g.find(nval);
        if (it != g.end() && cost[it->second] == -1) {
          cost[it->second] = 1;
          que2.push(it->second);
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
  res = min(res, bfs(1, 0, 0, n, m));
  res = min(res, bfs(1, 0, 0, n, m));
  res = min(res, bfs(0, 0, 0, n, m));
  res = min(res, bfs(0, 0, 0, n, m));
  printf("%d\n", res);
  return 0;
}