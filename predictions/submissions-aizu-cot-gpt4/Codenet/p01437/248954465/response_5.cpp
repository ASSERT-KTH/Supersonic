#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cstring>

typedef long long int64;

void dfs(int x, int y, int v, int64 step, const std::array<int, 4>& vx, const std::array<int, 4>& vy,
         const std::string& tmp, std::vector<std::vector<std::vector<int64>>>& nxt, 
         const std::vector<std::string>& C, int H, int W) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
  if (step == 0) {
    std::cout << y + 1 << " " << x + 1 << " " << tmp[v] << '\n';
    return;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
    nxt[nx][ny][v] = nxt[x][y][v] + 1;
    return (dfs(nx, ny, v, (step - 1) % loop, vx, vy, tmp, nxt, C, H, W));
  } else {
    nxt[x][y][nv] = nxt[x][y][v];
    return (dfs(x, y, nv, step, vx, vy, tmp, nxt, C, H, W));
  }
}

int main() {
  const std::array<int, 4> vy = {-1, 0, 1, 0}, vx = {0, 1, 0, -1};
  const std::string tmp = "NESW";
  int H, W, sx, sy, sv;
  int64 L;
  while (std::cin >> H >> W >> L, H) {
    std::vector<std::vector<std::vector<int64>>> nxt(W, std::vector<std::vector<int64>>(H, std::vector<int64>(4, -1)));
    std::vector<std::string> C(H);
    for (int i = 0; i < H; i++) {
      std::cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = tmp.find(C[i][j]);
        if (p != std::string::npos)
          sx = j, sy = i, sv = p;
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L, vx, vy, tmp, nxt, C, H, W);
  }
}