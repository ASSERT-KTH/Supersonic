#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H, sx, sy, gx, gy;
int csize, wsize;
char wx[3], wy[3], cx[3], cy[3];
char field[16][16];

bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  if (field[ty][tx] != 'w')
    return true;
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty)
      return true;
  }
  return false;
}

bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i)))
      return true;
  }
  return false;
}

void BFS(char nx, char ny, char ncx[], char ncy[], char Sc, int bfscost[10][10]) {
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    for (int k = 0; k < 4; k++) {
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
    int res = INT_MAX;
    priority_queue<pair<int, vector<char>>, vector<pair<int, vector<char>>>,
                   greater<pair<int, vector<char>>>>
        q;
    map<vector<char>, int> DP;
    vector<char> state(8);
    state[0] = cx[0];
    state[1] = cy[0];
    state[2] = cx[1];
    state[3] = cy[1];
    state[4] = cx[2];
    state[5] = cy[2];
    state[6] = sx;
    state[7] = sy;
    q.push(make_pair(0, state));
    DP[state] = 0;
    while (!q.empty()) {
      int cost = q.top().first;
      vector<char> state = q.top().second;
      char nx = state[6], ny = state[7];
      char tSc = state[4] | (state[5] << 1) | (state[3] << 2);
      char ncx[3], ncy[3];
      for (int i = 0; i < csize; i++) {
        ncx[i] = state[i * 2];
        ncy[i] = state[i * 2 + 1];
      }
      q.pop();
      if (res <= cost)
        break;
      int bfscost[10][10];
      BFS(nx, ny, ncx, ncy, tSc, bfscost);
      if (bfscost[gy][gx] != -1)
        res = min(res, cost + bfscost[gy][gx]);
      for (int i = 0; i < csize; i++) {
        if (!(tSc & (1 << i))) {
          for (int j = 0; j < 4; j++) {
            int tx = ncx[i] + dx[j];
            int ty = ncy[i] + dy[j];
            if (bfscost[ty][tx] == -1)
              continue;
            char ttSc = tSc;
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
            vector<char> nextState(8);
            for (int k = 0; k < csize; k++) {
              nextState[k * 2] = ncx[k];
              nextState[k * 2 + 1] = ncy[k];
            }
            nextState[6] = tcx;
            nextState[7] = tcy;
            int *dpp = &DP[nextState];
            if (*dpp == 0 || *dpp > cost + bfscost[ty][tx]) {
              *dpp = cost + bfscost[ty][tx];
              q.push(make_pair(cost + bfscost[ty][tx], nextState));
            }
          }
        }
      }
    }
    printf("%d\n", res == INT_MAX ? -1 : res);
  }
  return 0;
}