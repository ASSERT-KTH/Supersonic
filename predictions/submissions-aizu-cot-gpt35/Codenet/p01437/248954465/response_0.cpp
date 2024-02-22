#include <iostream>
#include <string>
using namespace std;

const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

void dfs(int x, int y, int v, long long step) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << "NESW"[v] << endl;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    long long loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
    nxt[nx][ny][v] = nxt[x][y][v] + 1;
    dfs(nx, ny, v, (step - 1) % loop);
  } else {
    nxt[x][y][nv] = nxt[x][y][v];
    dfs(x, y, nv, step);
  }
}

int main() {
  int H, W;
  long long L;
  while (cin >> H >> W >> L, H) {
    int sx, sy, sv;
    long long nxt[100][100][4];
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < H; i++) {
      string row;
      cin >> row;
      for (int j = 0; j < W; j++) {
        if (row[j] == 'N') {
          sx = j, sy = i, sv = 0;
        } else if (row[j] == 'E') {
          sx = j, sy = i, sv = 1;
        } else if (row[j] == 'S') {
          sx = j, sy = i, sv = 2;
        } else if (row[j] == 'W') {
          sx = j, sy = i, sv = 3;
        }
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}