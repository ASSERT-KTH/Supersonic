#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n, m, k;
int x[100001], y[100001];
vector<int> g;
vector<int> cost;

int bfs(int startX, int startY) {
  vector<int> que;
  vector<int> que2;
  bool flag = false;
  cost.assign(k, -1);

  ll startIdx = (ll)startY * n + startX;
  if (startIdx < g.size()) {
    que.push_back(g[startIdx]);
    cost[g[startIdx]] = 0;
  }

  int dx[] = {-2, -1, 0, 1, 2};
  int dy[] = {-2, -1, 0, 1, 2};

  for (int i = 0; i < que.size(); i++) {
    int q = que[i];
    int qx = x[q];
    int qy = y[q];

    for (int di = 0; di < 5; di++) {
      for (int dj = 0; dj < 5; dj++) {
        int ni = qy + dy[di];
        int nj = qx + dx[dj];

        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          continue;

        ll nval = (ll)ni * n + nj;
        if (nval < g.size()) {
          int nc = (abs(dx[dj]) > 1 || abs(dy[di]) > 1) ? 1 : 0;
          if (cost[g[nval]] == -1) {
            cost[g[nval]] = nc;
            if (nc == 0)
              que.push_back(g[nval]);
            if (nc == 1)
              que2.push_back(g[nval]);
          } else if (cost[g[nval]] == 1 && nc == 0) {
            cost[g[nval]] = 0;
            que.push_back(g[nval]);
          }
        }
      }
    }
  }

  if (flag)
    return 1;

  for (int i = 0; i < que2.size(); i++) {
    int q = que2[i];
    int qx = x[q];
    int qy = y[q];

    for (int di = -1; di <= 1; di++) {
      for (int dj = -1; dj <= 1; dj++) {
        int ni = qy + dy[di];
        int nj = qx + dx[dj];

        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          return 1;

        ll nval = (ll)ni * n + nj;
        if (nval < g.size()) {
          if (cost[g[nval]] == -1) {
            cost[g[nval]] = 1;
            que2.push_back(g[nval]);
          }
        }
      }
    }
  }

  return 2;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &k);
  
  g.resize((ll)n * m);
  cost.resize(k, -1);

  for (int i = 0; i < k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    ll idx = (ll)y[i] * n + x[i];
    if (idx < g.size()) {
      g[idx] = i;
    }
  }

  int res = 2;
  res = min(res, bfs(1, 0));