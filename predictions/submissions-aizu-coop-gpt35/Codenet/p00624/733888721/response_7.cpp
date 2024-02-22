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
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x)                                                         \
  for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3], cx[3], cy[3];
vector<string> field;
vector<vector<vector<vector<vector<vector<vector<vector<char>>>>>>>> DP;
struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0] = _cy[0], cy[1] = _cy[1], cy[2] = _cy[2];
  }
  bool operator<(const state &a) const {
    if (x != a.x)
      return x < a.x;
    if (y != a.y)
      return y < a.y;
    if (cx[0] != a.cx[0])
      return cx[0] < a.cx[0];
    if (cx[1] != a.cx[1])
      return cx[1] < a.cx[1];
    if (cx[2] != a.cx[2])
      return cx[2] < a.cx[2];
    if (cy[0] != a.cy[0])
      return cy[0] < a.cy[0];
    if (cy[1] != a.cy[1])
      return cy[1] < a.cy[1];
    if (cy[2] != a.cy[2])
      return cy[2] < a.cy[2];
    return Sc < a.Sc;
  }
  bool operator==(const state &a) const {
    return (x == a.x && y == a.y &&
            (cx[0] == a.cx[0] && cx[1] == a.cx[1] && cx[2] == a.cx[2]) &&
            (cy[0] == a.cy[0] && cy[1] == a.cy[1] && cy[2] == a.cy[2]) &&
            Sc == a.Sc);
  }
};
bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  int i;
  if (field[ty][tx] != 'w')
    return true;
  rep(i, csize) if (ncx[i] == tx && ncy[i] == ty) return true;
  return false;
}
bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  int i;
  rep(i,
      csize) if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i))) return true;
  return false;
}
void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  int i, j, k;
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    rep(k, 4) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 ||
          iscontena(tx, ty, ncx, ncy, Sc))
        continue;
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy))
        continue;
      bfscost[ty][tx] = cost + 1;
      q.push(make_pair(tx, ty));
    }
  }
}
void input() {
  int i, j;
  rep(i, H) {
    string line;