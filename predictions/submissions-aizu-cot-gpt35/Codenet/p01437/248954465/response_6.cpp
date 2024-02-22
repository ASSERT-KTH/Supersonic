#include <iostream>
#include <cstring>
using namespace std;
typedef long long int64;

const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

int H, W;
int64 L;
string C[100];
int sx, sy, sv;
int64 nxt[100][100][4];

void dfs(int x, int y, int v, int64 step) {
  while (true) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;

    if (step == 0) {
      cout << y + 1 << " " << x + 1 << " " << "NESW"[v] << '\n';
      return;
    } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      x = nx; y = ny; v = v; step = (step - 1) % loop;
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      x = x; y = y; v = nv; step = step;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> H >> W >> L, H) {
    std::fill(&nxt[0][0][0], &nxt[0][0][0] + sizeof(nxt) / sizeof(int64), -1);

    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = "NESW".find(C[i][j]);
        if (p != string::npos)
          sx = j, sy = i, sv = p;
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }

  return 0;
}