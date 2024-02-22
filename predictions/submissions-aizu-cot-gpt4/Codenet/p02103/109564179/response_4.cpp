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

int bfs() {
  //...
  while (que.size()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1)
          continue;
        ll nval = (ll)ny * n + nx;
        auto iter = g.find(nval);
        if (iter != g.end()) {
          if (cost[iter->second] == -1) {
            cost[iter->second] = nc;
            if (nc == 0)
              que.push(iter->second);
            if (nc == 1)
              que2.push(iter->second);
          } else if (cost[iter->second] == 1 && nc == 0) {
            cost[iter->second] = 0;
            que.push(iter->second);
          }
        }
      }
    }
  }
  //...
  return 2;
}

// Similarly optimize bfs2(), bfs3(), bfs4()

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    g[(ll)y[i] * n + x[i]] = i;
  }
  int res = 2;
  res = min(res, bfs());
  res = min(res, bfs2());
  res = min(res, bfs3());
  res = min(res, bfs4());
  printf("%d\n", res);
  return 0;
}