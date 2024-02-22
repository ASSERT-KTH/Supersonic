#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long int64;

const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
string C[100];
int sx, sy, sv;
int64 nxt[100][100][4];
unordered_map<char, int> direction = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};

void dfs(int x, int y, int v, int64 step) {
  while (true) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (step == 0) {
      cout << y + 1 << " " << x + 1 << " " << "NESW"[v] << endl;
      return;
    } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      x = nx; y = ny; step = (step - 1) % loop;
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      v = nv;
    }
  }
}

int main() {
  while (cin >> H >> W >> L, H) {
    for(int i=0; i<100; i++)
      for(int j=0; j<100; j++)
        for(int k=0; k<4; k++)
          nxt[i][j][k] = -1;
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        if (direction.count(C[i][j]))
          sx = j, sy = i, sv = direction[C[i][j]];
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}