#include <iostream>
#include <cstring>
using namespace std;

typedef long long int64;

const char tmp[] = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

int H, W;
int64 L;
char C[100][100];
int sx, sy, sv;
int64 nxt[100][100];

int main() {
  while (cin >> H >> W >> L, H) {
    memset(nxt, -1, sizeof(nxt[0][0]) * H * W);
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        for (int p = 0; p < 4; p++) {
          if (C[i][j] == tmp[p]) {
            sx = j, sy = i, sv = p;
            break;
          }
        }
      }
    }
    nxt[sx][sy] = 0;
    int x = sx, y = sy, v = sv;
    while (L > 0) {
      int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
      if (L == 0) {
        cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
        break;
      } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
        int64 loop = ~nxt[nx][ny] ? nxt[x][y] - nxt[nx][ny] + 1 : L;
        nxt[nx][ny] = nxt[x][y] + 1;
        x = nx;
        y = ny;
        v = v;
        L = (L - 1) % loop;
        continue;
      } else {
        nxt[x][y] = nxt[x][y];
        x = x;
        y = y;
        v = nv;
        L = L;
        continue;
      }
    }
  }
}