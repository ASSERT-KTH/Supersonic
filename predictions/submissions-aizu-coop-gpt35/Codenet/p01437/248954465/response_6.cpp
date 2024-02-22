#include <iostream>
#include <vector>
using namespace std;

const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

int H, W;
int64 L;
vector<string> C;
int sx, sy, sv;

int64 dfs(int x, int y, int v, int64 step) {
  int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;

  if (step == 0) {
    cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
    return 0;
  }
  
  if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
    int64 loop = -1;
    if (nx != x || ny != y || nv != v)
      loop = step - 1;
    return dfs(nx, ny, v, loop % (step - loop == 0 ? 1 : step - loop));
  } else {
    return dfs(x, y, nv, step);
  }
}

int main() {
  while (cin >> H >> W >> L, H) {
    C.resize(H);
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = tmp.find(C[i][j]);
        if (p != string::npos) {
          sx = j, sy = i, sv = p;
        }
      }
    }
    dfs(sx, sy, sv, L);
  }
  return 0;
}