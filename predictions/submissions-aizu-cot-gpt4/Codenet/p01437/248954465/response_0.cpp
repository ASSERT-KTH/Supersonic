#include <bits/stdc++.h>
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
  while (step > 0) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    int64 &cur = nxt[x][y][v];
    if (step == 0) {
      cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
      break;
    } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? cur - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = cur + 1;
      step = (step - 1) % loop;
      x = nx;
      y = ny;
    } else {
      nxt[x][y][nv] = cur;
      v = nv;
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
        if (p != string::npos)
          sx = j, sy = i, sv = p;
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}