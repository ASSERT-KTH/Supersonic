#include <cstdio>
#include <cstring>
typedef long long int64;
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
char C[100][101];
int64 nxt[100][100];
int dir[100][100];
int main() {
  int H, W;
  int64 L;
  while (scanf("%d%d%lld", &H, &W, &L), H) {
    memset(nxt, -1, sizeof(nxt));
    memset(dir, -1, sizeof(dir));
    int sx, sy, sv;
    for (int i = 0; i < H; i++) {
      scanf("%s", C[i]);
      for (int j = 0; j < W; j++) {
        if (C[i][j] >= 'A' && C[i][j] <= 'Z') {
          sx = j, sy = i, sv = C[i][j] - 'A';
        }
      }
    }
    int x = sx, y = sy, v = sv;
    nxt[y][x] = 0;
    dir[y][x] = v;
    for (int64 step = 0; step < L; ) {
      int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
      if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
        if (nxt[ny][nx] != -1 && dir[ny][nx] == v) {
          int64 loop = step - nxt[ny][nx] + 1;
          if (L - step > loop) {
            step += (L - step) / loop * loop;
            continue;
          }
        }
        nxt[ny][nx] = ++step;
        dir[ny][nx] = v;
        x = nx, y = ny;
      } else {
        v = nv;
      }
    }
    printf("%d %d %c\n", y + 1, x + 1, "NESW"[v]);
  }
}