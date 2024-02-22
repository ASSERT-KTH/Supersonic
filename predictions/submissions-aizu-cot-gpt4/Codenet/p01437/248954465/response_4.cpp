#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;
typedef long long int64;
const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
map<char, int> dir = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

void dfs(int64 nxt[100][100][4], string C[100], int x, int y, int v, int64 step, int H, int W) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << "\n";
    return;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
    nxt[nx][ny][v] = nxt[x][y][v] + 1;
    return (dfs(nxt, C, nx, ny, v, (step - 1) % loop, H, W));
  } else {
    nxt[x][y][nv] = nxt[x][y][v];
    return (dfs(nxt, C, x, y, nv, step, H, W));
  }
}

int main() {
  int H, W, sx, sy, sv;
  int64 L;
  string C[100];
  while (cin >> H >> W >> L, H) {
    int64 nxt[100][100][4];
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        if (dir.find(C[i][j]) != dir.end()) {
          sx = j, sy = i, sv = dir[C[i][j]];
          break;
        }
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(nxt, C, sx, sy, sv, L, H, W);
  }
}