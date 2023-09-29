#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
vector<string> C;
int sx, sy, sv;
vector<vector<vector<int64>>> nxt;
void dfs(int x, int y, int v, int64 step) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
    return;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
    nxt[nx][ny][v] = nxt[x][y][v] + 1;
    return (dfs(nx, ny, v, (step - 1) % loop));
  } else {
    nxt[x][y][nv] = nxt[x][y][v];
    return (dfs(x, y, nv, step));
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> H >> W >> L, H) {
    nxt.assign(W, vector<vector<int64>>(H, vector<int64>(4, -1)));
    C.resize(H);
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