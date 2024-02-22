#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
int n, m, k;
int x[100001], y[100001];
vector<int> g[100001];
int cost[100001];

int bfs(queue<int>& que, queue<int>& que2) {
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        ll nval = (ll)ny * n + nx;
        if (!g[nval].empty()) {
          int idx = g[nval][0];
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
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          continue;
        ll nval = (ll)ny * n + nx;
        if (!g[nval].empty()) {
          int idx = g[nval][0];
          if (cost[idx] == -1) {
            cost[idx] = 1;
            que2.push(idx);
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
    g[(ll)y[i] * n + x[i]].push_back(i);
  }
  queue<int> que, que2;
  int res = 2;
  for (int i = 1; i <= m - 1; i++) {
    ll val = (ll)i * n;
    if (!g[val].empty()) {
      que.push(g[val][0]);
      cost[g[val][0]] = 0;
    }
  }
  res = min(res, bfs(que, que2));
  while (!que.empty())
    que.pop();
  while (!que2.empty())
    que2.pop();
  for (int i = 1; i <= n - 1; i++) {
    ll val = i;
    if (!g[val].empty()) {
      que.push(g[val][0]);
      cost[g[val][0]] = 0;
    }