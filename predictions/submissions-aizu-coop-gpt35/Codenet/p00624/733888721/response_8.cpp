#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

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

void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  int bfscost[10][10];
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

void input(int& H, int& W, int& sx, int& sy, int& gx, int& gy, int& csize, int& wsize, char wx[], char wy[], char cx[], char cy[]) {
  cin >> H >> W;
  if (H == 0 && W == 0) return;
  csize = wsize = 0;
  for (int i = 0; i < H; i++) {
    cin >> field[i];
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
  int H, W, sx, sy, gx, gy, csize, wsize;
  char wx[3], wy[3], cx[3], cy[3];
  while (1) {
    input(H, W, sx, sy, gx, gy, csize, wsize, wx, wy, cx, cy);
    if (H == 0 && W == 0) break;

    int res = INT_MAX;
    queue<pair<int, state>> q;
    vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>> DP(9,
        vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>(9,
          vector<vector<vector<vector<vector<vector<int>>>>>>>(9,
            vector<vector<vector<vector<vector<int>>>>>(9,
              vector<vector<vector<vector<int>>>>(9,
                vector<vector<vector<int>>>(9,
                  vector<vector<int>>(9,
                    vector<int>(9,
                      -1)))))));

    q.push(make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    while (!q.empty()) {
      int cost = q.front().first;
      char nx = q.front().second.x, ny = q.front().second.y;
      char tSc = q.front().second.Sc;
      char ncx[3], ncy[3];
      for (int i = 0; i < 3; i++) {
        ncx[i] = q.front().second.cx[i];
        ncy[i] = q.front().second.cy[i];
      }
      q.pop();
      if (res <= cost)