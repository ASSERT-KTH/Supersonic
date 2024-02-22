#include <iostream>
#include <cstring>
#include <map>
using namespace std;
typedef long long int64;
map<char, int> dirMap = {{'N', 0}, {'E', 1}, {'S', 2}, {'W', 3}};
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
string C[100];
int sx, sy, sv;
int64 nxt[100][100][4];

void dfs(int x, int y, int v, int64 step) {
  stack<tuple<int, int, int, int64>> stk;
  stk.push(make_tuple(x, y, v, step));

  while (!stk.empty()) {
    tie(x, y, v, step) = stk.top();
    stk.pop();

    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (step == 0) {
      cout << y + 1 << " " << x + 1 << " " << dirMap[v] << endl;
      return;
    } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
      nxt[nx][ny][v] = nxt[x][y][v] + 1;
      stk.push(make_tuple(nx, ny, v, (step - 1) % loop));
    } else {
      nxt[x][y][nv] = nxt[x][y][v];
      stk.push(make_tuple(x, y, nv, step));
    }
  }
}

int main() {
  while (cin >> H >> W >> L, H) {
    memset(nxt, -1, sizeof(nxt));
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = dirMap[C[i][j]];
        if (p != dirMap.end())
          sx = j, sy = i, sv = p;
      }
    }
    nxt[sx][sy][sv] = 0;
    dfs(sx, sy, sv, L);
  }
}