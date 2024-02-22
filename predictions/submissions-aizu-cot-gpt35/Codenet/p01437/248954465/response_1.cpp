#include <iostream>
#include <vector>
#include <cstring>

const std::string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0};
const int vx[] = {0, 1, 0, -1};

void dfs(int x, int y, int v, long long step, std::vector<std::string>& C) {
  int H = C.size();
  int W = C[0].size();

  while (true) {
    int nx = x + vx[v];
    int ny = y + vy[v];
    int nv = (v + 1) % 4;

    if (step == 0) {
      std::cout << y + 1 << " " << x + 1 << " " << tmp[v] << std::endl;
      return;
    } else if (0 <= nx && nx < W && 0 <= ny && ny < H && C[ny][nx] != '#') {
      int loop = -1;
      if (nx < W && ny < H) {
        loop = nx - x + ny - y + 1;
      }

      if (loop != -1) {
        step = (step - 1) % loop;
      }
      
      x = nx;
      y = ny;
    } else {
      v = nv;
    }
  }
}

int main() {
  int H, W;
  long long L;

  while (std::cin >> H >> W >> L, H) {
    std::vector<std::string> C(H);

    for (int i = 0; i < H; i++) {
      std::cin >> C[i];
    }

    int sx = -1, sy = -1, sv = -1;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        char c = C[i][j];

        for (int k = 0; k < 4; k++) {
          if (c == tmp[k]) {
            sx = j;
            sy = i;
            sv = k;
            break;
          }
        }

        if (sx != -1 && sy != -1 && sv != -1) {
          break;
        }
      }

      if (sx != -1 && sy != -1 && sv != -1) {
        break;
      }
    }

    dfs(sx, sy, sv, L, C);
  }

  return 0;
}