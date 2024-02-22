#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <unordered_map>
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
unordered_map<ll, int> g;
int cost[100001];

// Optimized BFS function
int bfsOptimized(int start, int end, bool isX) {
  queue<int> que, que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = start; i < end; i++) {
    ll val = isX ? i : (ll)i * n;
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
        int nc = (abs(i) > 1 || abs(j) > 1) ? 1 : 0;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0 || ny < 0 || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1)
          continue;
        if (isX ? (ny < 0 || ny >= m) : (nx < 0 || nx >= n)) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
          continue;
        }
        ll nval = (ll)ny * n + nx;
        auto it = g.find(nval);
        if (it != g.end()) {
          if (cost[it->second] == -1) {
            cost[it->second] = nc;
            (nc == 0 ? que : que2).push(it->second);
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
        if (nx < 0 || ny < 0 || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1)
          continue;
        if (isX ? (ny < 0 || ny >= m) : (nx < 0 || nx >= n))
          return 1;
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
  res = min(res, bfsOptimized(1, m - 1, true));  // replaces bfs()
  res = min(res, bfsOptimized(1, n - 1, false)); // replaces bfs2()
  res = min(res, bfsOptimized(0, n - 2, true));  // replaces bfs3()
  res = min(res, bfsOptimized(0, m - 2, false)); // replaces bfs4()
  printf("%d\n", res);
  return 0;
}