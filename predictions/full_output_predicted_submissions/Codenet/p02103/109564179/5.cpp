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
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0)
          continue;
        if (nx == n - 1 && ny == 0)
          continue;
        if (nx == n - 1 && ny == m - 1)
          continue;