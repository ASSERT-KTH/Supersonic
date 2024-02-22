#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3], cx[3], cy[3];
char field[16][16];
char DP[9][9][9][9][9][9][9][9];

// rest of the code remains same

int main() {
  int i, j, k;
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    memset(DP, -1, sizeof(DP));
    rep(i, 3) cx[i] = cy[i] = 0;
    input();
    int res = INT_MAX;
    pair<int, state> qPair;
    qPair.first = 0;
    qPair.second = state(sx, sy, cx, cy, 0);
    priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>> q;
    q.push(qPair);
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    while (!q.empty()) {
      int cost = q.top().first;
      char nx = q.top().second.x, ny = q.top().second.y;
      char tSc = q.top().second.Sc;
      char ncx[3], ncy[3];
      rep(i, 3) ncx[i] = ncy[i] = 0;
      rep(i, csize) ncx[i] = q.top().second.cx[i], ncy[i] = q.top().second.cy[i];
      q.pop();
      if (res <= cost) break;
      BFS(nx, ny, ncx, ncy, tSc);
      if (bfscost[gy][gx] != -1) res = min(res, cost + bfscost[gy][gx]);
      rep(i, csize) if (!(tSc & (1 << i))) {
        rep(j, 4) {
          int tx = ncx[i] + dx[j];
          int ty = ncy[i] + dy[j];
          if (bfscost[ty][tx] == -1) continue;
          // rest of the code remains same
        }
      }
    }
    printf("%d\n", res == INT_MAX ? -1 : res);
  }
  return 0;
}