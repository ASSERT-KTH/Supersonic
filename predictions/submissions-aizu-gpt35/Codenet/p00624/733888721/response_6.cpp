#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
const int MAX_H = 16, MAX_W = 16, MAX_M = 3;
const int INF = 1e9;

int W, H, sx, sy, gx, gy;
char field[MAX_H][MAX_W];
int csize, wsize;
int wx[MAX_M], wy[MAX_M], cx[MAX_M], cy[MAX_M];
char DP[MAX_M][MAX_M][MAX_M][MAX_H][MAX_W][MAX_H][MAX_W];
int bfscost[MAX_H][MAX_W];

struct state {
  char x, y, Sc;
  char cx[MAX_M], cy[MAX_M];
  state(char _x, char _y, char* _cx, char* _cy, char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    memcpy(cx, _cx, sizeof(cx));
    memcpy(cy, _cy, sizeof(cy));
  }
  bool operator<(const state& a) const {
    if (x != a.x) return x < a.x;
    if (y != a.y) return y < a.y;
    if (Sc != a.Sc) return Sc < a.Sc;
    for (int i = 0; i < csize; ++i) {
      if (cx[i] != a.cx[i]) return cx[i] < a.cx[i];
      if (cy[i] != a.cy[i]) return cy[i] < a.cy[i];
    }
    return false;
  }
  bool operator==(const state& a) const {
    if (x != a.x || y != a.y || Sc != a.Sc) return false;
    for (int i = 0; i < csize; ++i) {
      if (cx[i] != a.cx[i] || cy[i] != a.cy[i]) return false;
    }
    return true;
  }
};

bool isdel(char tx, char ty, char* ncx, char* ncy) {
  if (field[ty][tx] != 'w') return true;
  for (int i = 0; i < csize; ++i) {
    if (ncx[i] == tx && ncy[i] == ty) return true;
  }
  return false;
}

bool iscontena(char tx, char ty, char* ncx, char* ncy, char Sc) {
  for (int i = 0; i < csize; ++i) {
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i))) return true;
  }
  return false;
}

void BFS(char nx, char ny, char* ncx, char* ncy, char Sc) {
  queue<pair<int, int>> q;
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  q.emplace(nx, ny);
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 || iscontena(tx, ty, ncx, ncy, Sc)) continue;
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy)) continue;
      bfscost[ty][tx] = cost + 1;
      q.emplace(tx, ty);
    }
  }
}

int solve() {
  priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>> q;
  memset(DP, -1, sizeof(DP));
  q.emplace(0, state(sx, sy, cx, cy, 0));
  DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
  int res = INF;
  while (!q.empty()) {
    auto [cost, cur] = q.top();
    q.pop();
    if (cost >= res) break;
    BFS(cur.x, cur.y, cur.cx, cur.cy, cur.Sc);
    if (bfscost[gy][gx] != -1) res = min(res, cost + bfscost[gy][gx]);
    for (int i = 0; i < csize; ++i) {
      if (!(cur.Sc & (1 << i))) {
        for (int j = 0; j < 4; ++j) {
          int tx = cur.cx[i] + dx[j];
          int ty = cur.cy[i] + dy[j];
          if (bfscost[ty][tx] == -1) continue;
          int ttSc = cur.Sc;
          int dir = (j + 2) % 4;
          int tcx = cur.cx[i], tcy = cur.cy[i];
          while (true) {
            int ay = tcy + dy[dir];
            int ax = tcx + dx[dir];
            if (field[ay][ax] == '#' || iscontena(ax, ay, cur.cx, cur.cy, cur.Sc)) break;
            tcx += dx[dir];
            tcy += dy[dir];
            if (field[ay][ax] == 'w' && !isdel(ax, ay, cur.cx, cur.cy)) {
              ttSc |= 1 << i;
              break;
            }
          }
          if (tcx == cur.cx[i] && tcy == cur.cy[i]) continue;
          char ttcx[MAX_M], ttcy[MAX_M];
          memcpy(ttcx, cur.cx, sizeof(ttcx));
          memcpy(ttcy, cur.cy, sizeof(ttcy));
          ttcx[i] = tcx, ttcy[i] = tcy;
          char* dpp = &DP[ttcx[0]][ttcy[0]][ttcx[1]][ttcy[1]][ttcx[2]][ttcy[2]][tx][ty];
          if (*dpp == -1 || *dpp > cost + bfscost[ty][tx]) {
            *dpp = cost + bfscost[ty][tx];
            q.emplace(cost + bfscost[ty][tx], state(tx, ty, ttcx, ttcy, ttSc));
          }
        }
      }
    }
  }
  return res == INF ? -1 : res;
}

int main() {
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    for (int i = 0; i < H; ++i) {
      scanf("%s", field[i]);
      for (int j = 0; j < W; ++j) {
        if (field[i][j] == '@') sx = j, sy = i;
        if (field[i][j] == 'E') gx = j, gy = i;
        if (field[i][j] == 'w') wx[wsize] = j, wy[wsize] = i, ++wsize;
        if (field[i][j] == 'c') cx[csize] = j, cy[csize] = i, ++csize;
      }
    }
    printf("%d\n", solve());
  }
  return 0;
}