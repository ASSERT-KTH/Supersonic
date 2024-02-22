#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <vector>

#define MOD 1000000007LL

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n, m, k;
int x[100001], y[100001];
set<ll> g;
int cost[100001];

int bfs(int sx, int sy) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  
  ll val = (ll)sy * n + sx;
  if (g.find(val) != g.end()) {
    que.push(g[val]);
    cost[g[val]] = 0;
  }

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    
    for (int i = -1; i <= 1; i += 2) {
      for (int j = -1; j <= 1; j += 2) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        
        if (nx == 0 && ny == 0)
          continue;
        if (nx == n - 1 && ny == m - 1)
          continue;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        }
        
        ll nval = (ll)ny * n + nx;
        if (g.find(nval) != g.end()) {
          if (cost[g[nval]] == -1) {
            cost[g[nval]] = nc;
            if (nc == 0)
              que.push(g[nval]);
            if (nc == 1)
              que2.push(g[nval]);
          } else if (cost[g[nval]] == 1 && nc == 0) {
            cost[g[nval]] = 0;
            que.push(g[nval]);
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
        
        if (nx == 0 && ny == 0)
          continue;