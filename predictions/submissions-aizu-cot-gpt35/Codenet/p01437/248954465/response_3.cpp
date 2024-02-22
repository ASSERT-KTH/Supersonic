#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long int64;

const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
string C[100];
int sx, sy, sv;
int64 nxt[100][100][4];

void dfs(int x, int y, int v, int64 step) {
  int nx, ny, nv;
  while (step > 0) {
    nx = x + vx[v];
    ny = y + vy[v];
    nv = (v + 1) % 4;

    if (step == 1) {
      cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
      return;
    } else if (nx >= 0 && ny >= 0 && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      step = (step - 1) % loop;
      x = nx;
      y = ny;
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      v = nv;
      step--;
    }
  }
}

int main() {
  while (cin >> H >> W >> L, H) {
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = tmp.find(C[i][j]);
        if (p != -1) {
          sx = j;
          sy = i;
          sv = p;
        }
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}