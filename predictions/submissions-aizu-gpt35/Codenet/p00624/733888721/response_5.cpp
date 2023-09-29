#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<(n); i++)
#define rrep(i, n) for(int i=1; i<=(n); i++)
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

int W, H, sx, sy, gx, gy;
int bfscost[10][10];
char csize, wsize, wx[3], wy[3], cx[3], cy[3];
char field[16][16];
char DP[9][9][9][9][9][9][9][9];

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
  rep(i, H) {
    scanf("%s", field[i]);
    rep(j, W) {
      if (field[i][j] == '@')
        sx = j, sy = i;
      if (field[i][j] == 'E')
        gx = j, gy = i;
      if (field[i][j] == 'w') {
        wx[wsize] = j, wy[wsize] = i;
        wsize++;
      }
      if (field[i][j] == 'c') {
        cx[csize] = j, cy[csize] = i;
        csize++;
      }
    }
  }
}

int main() {
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    memset(DP, -1, sizeof(DP));
    rep(i, 3) cx[i] = cy[i] = 0;
    input();
    int res = INF;
    priority_queue<pair<int, state>, vector<pair<int, state>>,
                   greater<pair<int, state>>>
        q;
    q.push(make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    while (!q.empty()) {
      int cost = q.top().first;
      char nx = q.top().second.x, ny = q.top().second.y;
      char tSc = q.top().second.Sc;
      char ncx[3], ncy[3];
      rep(i, 3) ncx[i] = ncy[i] = 0;
      rep(i, csize) ncx[i] = q.top().second.cx[i],
                    ncy[i] = q.top().second.cy[i];
      q.pop();
      if (res <= cost)
        break;
      BFS(nx, ny, ncx, ncy, tSc);
      if (bfscost[gy][gx] != -1)
        res = min(res, cost + bfscost[gy][gx]);
      rep(i, csize) if (!(tSc & (1 << i))) {
        rep(j, 4) {
          int tx = ncx[i] + dx[j];
          int ty = ncy[i] + dy[j];
          if (bfscost[ty][tx] == -1)
            continue;
          int ttSc = tSc;
          int dir = (j + 2) % 4;
          int tcx = ncx[i], tcy = ncy[i];
          for (;;) {
            int ay = tcy + dy[dir];
            int ax = tcx + dx[dir];
            if (field[ay][ax] == '#' || iscontena(ax, ay, ncx, ncy, tSc))
              break;
            tcx += dx[dir];
            tcy += dy[dir];
            if (field[ay][ax] == 'w' && !isdel(ax, ay, ncx, ncy)) {
              ttSc |= 1 << i;
              break;
            }
          }
          if (tcx == ncx[i] && tcy == ncy[i])
            continue;
          char ttcx[3], ttcy[3];
          rep(k, 3) ttcx[i] = ttcy[i] = 0;
          rep(k, csize) ttcx[k] = ncx[k], ttcy[k] = ncy[k];
          ttcx[i] = tcx, ttcy[i] = tcy;
          char *dpp =
              &DP[ttcx[0]][ttcy[0]][ttcx[1]][ttcy[1]][ttcx[2]][ttcy[2]][tx][ty];
          if (*dpp == -1 || *dpp > cost + bfscost[ty][tx]) {
            *dpp = cost + bfscost[ty][tx];
            q.push(make_pair(cost + bfscost[ty][tx],
                             state(tx, ty, ttcx, ttcy, ttSc)));
          }
        }
      }
    }
    printf("%d\n", res == INF ? -1 : res);
  }
  return 0;
}