#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#define MOD 1000000007LL
using namespace std;

int n, m, k;
int x[100001], y[100001];
map<long long, int> g;
int cost[100001];

int bfs(int startX, int startY, int endX, int endY) {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  
  long long startVal = (long long)startY * n + startX;
  if (g.find(startVal) != g.end()) {
    que.push(g[startVal]);
    cost[g[startVal]] = 0;
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
        
        if (nx == startX && ny == startY)
          continue;
        if (nx == endX && ny == endY)
          continue;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        }
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          long long nval = (long long)ny * n + nx;
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
  }

  if (flag)
    return 1;
  
  while (que2.size()) {
    int q = que2.front();
    que2.pop();
    
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nc = 0;
        int nx = j + x[q], ny = i + y[q];
        
        if (nx == startX && ny == startY)
          continue;
        if (nx == endX && ny == endY)
          continue;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
          return 1;
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          long long nval = (long long)ny * n + nx;
          if (g.find(nval) != g.end()) {
            if (cost[g[nval]] == -1) {
              cost[g[nval]] = 1;
              que2.push(g[nval]);
            }
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
    g[(long long)y[i] * n + x[i]] = i;
  }
  
  int res = 2;
  res = min(res, bfs(0, 0, n - 1, m - 1));