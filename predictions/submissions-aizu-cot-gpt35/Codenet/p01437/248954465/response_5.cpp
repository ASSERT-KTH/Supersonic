#include <iostream>
#include <vector>
using namespace std;

const char* tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

void dfs(int x, int y, int v, long long step, vector<vector<char>>& C, vector<vector<vector<int>>>& nxt) {
  while (true) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (step == 0) {
      cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
      return;
    } else if (0 <= nx && 0 <= ny && nx < C[0].size() && ny < C.size() && C[ny][nx] != '#') {
      int64_t loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      step = (step - 1) % loop;
      x = nx;
      y = ny;
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      v = nv;
    }
  }
}

int main() {
  int H, W;
  long long L;
  while (cin >> H >> W >> L, H) {
    vector<vector<char>> C(H, vector<char>(W));
    vector<vector<vector<int>>> nxt(W, vector<vector<int>>(H, vector<int>(4, -1)));

    int sx, sy, sv;
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> C[i][j];
        int p = strchr(tmp, C[i][j]) - tmp;
        if (p != strlen(tmp))
          sx = j, sy = i, sv = p;
      }
    }

    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L, C, nxt);
  }
}