#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
enum Direction { NORTH, EAST, SOUTH, WEST };
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
string C[100];
int sx, sy, sv;
int64 nxt[100][100][4];
bool hit[100][100][4];
void dfs() {
  int x = sx, y = sy, v = sv;
  nxt[x][y][v] = 0;
  int64 step = L;
  while (step > 0) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (hit[y][x][v]) {
      nxt[x][y][nv] = nxt[x][y][v];
      v = nv;
    } else {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      step = (step - 1) % loop;
      x = nx, y = ny;
    }
    --step;
  }
  cout << y + 1 << " " << x + 1 << " ";
  switch (v) {
    case NORTH: cout << 'N'; break;
    case EAST:  cout << 'E'; break;
    case SOUTH: cout << 'S'; break;
    case WEST:  cout << 'W'; break;
  }
  cout << endl;
}
int main() {
  while (cin >> H >> W >> L, H) {
    memset(nxt, -1, sizeof(nxt));
    memset(hit, false, sizeof(hit));
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        if (C[i][j] == 'N') sx = j, sy = i, sv = NORTH;
        else if (C[i][j] == 'E') sx = j, sy = i, sv = EAST;
        else if (C[i][j] == 'S') sx = j, sy = i, sv = SOUTH;
        else if (C[i][j] == 'W') sx = j, sy = i, sv = WEST;
        else if (C[i][j] != '#') continue;
        for (int v = 0; v < 4; v++) {
          int nx = j + vx[v], ny = i + vy[v];
          if (!(0 <= nx && nx < W && 0 <= ny && ny < H && C[ny][nx] != '#')) {
            hit[i][j][v] = true;
          }
        }
      }
    }
    dfs();
  }
}