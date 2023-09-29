#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int64;
const char tmp[4] = {'N', 'E', 'S', 'W'};
const int vy[4] = {-1, 0, 1, 0}, vx[4] = {0, 1, 0, -1};
int64 nxt[100][100][4];
void dfs(int x, int y, int v, int64 step, const vector<string>& C, int H, int W) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
    return;
  } else if (0 <= nx && nx < W && 0 <= ny && ny < H && C[ny][nx] != '#') {
    int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
    nxt[nx][ny][v] = nxt[x][y][v] + 1;
    dfs(nx, ny, v, (step - 1) % loop, C, H, W);
  } else {
    nxt[x][y][nv] = nxt[x][y][v];
    dfs(x, y, nv, step, C, H, W);
  }
}
int main() {
  int H, W;
  int64 L;
  while (cin >> H >> W >> L, H) {
    memset(nxt, -1, sizeof(nxt));
    vector<string> C(H);
    int sx, sy, sv;
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (size_t j = 0; j < C[i].size(); j++) {
        const char* p = strchr(tmp, C[i][j]);
        if (p)
          sx = j, sy = i, sv = p - tmp;
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L, C, H, W);
  }
}