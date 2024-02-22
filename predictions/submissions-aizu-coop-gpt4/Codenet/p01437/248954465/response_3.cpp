#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
char C[100][100];
int sx, sy, sv;
int64 nxt[100][100][4];

void dfs(int x, int y, int v, int64 step) {
  while(true) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (step == 0) {
      printf("%d %d %c\n", y + 1, x + 1, "NESW"[v]);
      return;
    }
    if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      x = nx;
      y = ny;
      step = (step - 1) % loop;
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      v = nv;
    }
  }
}

int main() {
  while (scanf("%d %d %lld", &H, &W, &L), H) {
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < H; i++) {
      scanf("%s", C[i]);
      for (int j = 0; j < W; j++) {
        char c = C[i][j];
        if (c == 'N' || c == 'E' || c == 'S' || c == 'W') {
          sx = j, sy = i;
          switch (c) {
            case 'N': sv = 0; break;
            case 'E': sv = 1; break;
            case 'S': sv = 2; break;
            case 'W': sv = 3; break;
          }
        }
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}