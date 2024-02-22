#include <cstdio>
#include <cstring>
#define MOD 1000000007LL

typedef long long ll;

int n, m, k;
int x[100001], y[100001];
int cost[100001];
int res = 2;

void bfs(int dx, int dy) {
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
    
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nc = (abs(i) > 1 || abs(j) > 1) ? 1 : 0;
        int nx = j + x[q], ny = i + y[q];
        
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
          if (nc == 0) {
            res = 0;
            return;
          }
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
    res = 1;
  
  while (que2.size()) {
    int q = que2.front();
    que2.pop();
    
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nc = 0;
        int nx = j + x[q], ny = i + y[q];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          ll nval = (ll)ny * n + nx;
          if (g.find(nval) != g.end()) {
            if (cost[g[nval]] == -1) {
              cost[g[nval]] = 1;
              que2.push(g[nval]);
            }
          }
        } else {
          res = 1;
          return;
        }
      }
    }
  }
}

int main(void) {