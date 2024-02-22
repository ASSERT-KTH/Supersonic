#include <cstdio>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <utility>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H, sx, sy, gx, gy;
int csize, wsize;
char wx[3], wy[3], cx[3], cy[3];
char field[16][16];

struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    cx[0] = _cx[0], cx[1] = _cx[1], cx[2] = _cx[2];
    cy[0] = _cy[0], cy[1] = _cy[1], cy[2] = _cy[2];
  }
};

bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  if (field[ty][tx] != 'w')
    return true;
  for (int i = 0; i < csize; i++)
    if (ncx[i] == tx && ncy[i] == ty)
      return true;
  return false;
}

bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  for (int i = 0; i < csize; i++)
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i)))
      return true;
  return false;
}

void BFS(char nx, char ny, char ncx[], char ncy[], char Sc, int bfscost[]) {
  memset(bfscost, -1, sizeof(int) * W * H);
  bfscost[ny * W + nx] = 0;
  deque<pair<int, int>> q;
  q.push_back(make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y * W + x];
    q.pop_front();
    for (int k = 0; k < 4; k++) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (field[ty][tx] == '#' || bfscost[ty * W + tx] != -1 ||
          iscontena(tx, ty, ncx, ncy, Sc))
        continue;
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy))
        continue;
      bfscost[ty * W + tx] = cost + 1;
      q.push_back(make_pair(tx, ty));
    }
  }
}

void input() {
  for (int i = 0; i < H; i++) {
    scanf("%s", field[i]);
    for (int j = 0; j < W; j++) {
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
    input();
    int res = -1;
    map<pair<pair<char, char>, pair<char, char>>, int> DP;
    deque<pair<int, state>> q;
    q.push_back(make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[make_pair(make_pair(cx[0], cy[0]), make_pair(cx[1], cy[1]))] = 0;
    while (!q.empty()) {
      int cost = q.front().first;
      char nx = q.front().second.x, ny = q.front().second.y;
      char tSc = q.front().second.Sc;
      char ncx[3], ncy[3];
      for (int i = 0; i < csize; i++)
        ncx[i] = q.front().second.cx[i], ncy[i] = q.front().second.cy[i];
      q.pop_front();
      if (res != -1 && cost >= res)
        break;
      int bfscost[10][10];
      BFS(nx, ny, ncx, ncy, tSc, (int*)bfscost);
      if (bfscost[gy][gx] != -1) {
        if (res == -1)
          res = cost + bfscost[gy][gx];
        else
          res = min(res, cost + bfscost[gy][gx]);
      }
      for (int i = 0; i < csize; i++)
        if (!(tSc & (1 << i))) {
          for (int j = 0; j < 4; j++) {
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
            for (int k = 0; k < csize; k++)
              ttcx[k] = ncx[k], ttcy[k] = ncy[k];
            ttcx[i] = tcx, ttcy[i] = tcy;
            int& dpp = DP[make_pair(make_pair(ttcx[0], ttcy[0]), make_pair(ttcx[1], ttcy[1]))];
            if (dpp == 0 || dpp > cost + bfscost[ty][tx]) {
              dpp = cost + bfscost[ty][tx];
              q.push_back(make_pair(cost + bfscost[ty][tx],
                                    state(tx, ty, ttcx, ttcy, ttSc)));
            }
          }
        }
    }
    printf("%d\n", res);
  }
  return 0;
}