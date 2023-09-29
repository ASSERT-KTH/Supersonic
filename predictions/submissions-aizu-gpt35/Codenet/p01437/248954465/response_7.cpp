#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
const int maxH = 100, maxW = 100;
int H, W;
int64 L;
string C[maxH];
int sx, sy, sv;
int64 nxt[maxH][maxW][4];
void dfs(int x, int y, int v, int64 step) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
    return;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    int64 loop;
    if (~nxt[nx][ny][v]) loop = nxt[x][y][v] - nxt[nx][ny][v] + 1;
    else {
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      loop = -1;
    }
    return (dfs(nx, ny, v, (step - 1) % loop));
  } else {
    if (nxt[x][y][nv] == -1) nxt[x][y][nv] = nxt[x][y][v];
    return (dfs(x, y, nv, step));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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