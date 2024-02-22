#include <iostream>
using namespace std;

typedef long long int64;

const char tmp[] = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

int H, W;
int64 L;
char C[100][100];

int sx, sy, sv;

void dfs(int x, int y, int v, int64 step) {
  int nx = x + vx[v];
  int ny = y + vy[v];
  int nv = (v + 1) % 4;

  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
    return;
  } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    return dfs(nx, ny, v, (step - 1) % L);
  } else {
    return dfs(x, y, nv, step);
  }
}

int main() {
  while (cin >> H >> W >> L, H) {
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        cin >> C[i][j];
        if (C[i][j] != '#' && strchr(tmp, C[i][j]) != NULL) {
          sx = j;
          sy = i;
          sv = strchr(tmp, C[i][j]) - tmp;
        }
      }
    }
    dfs(sx, sy, sv, L);
  }
}