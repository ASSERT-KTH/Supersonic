#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void calc(P& N, int y, int x, int& tres) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (N[y][x] == Col) {
    tres++;
    N[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(N, y + dy[r], x + dx[r], tres);
  }
}
void on(P N, int count, int c, int& res) {
  if (count == 5) {
    int tres = 0;
    calc(N, 0, 0, tres);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  queue<C> Q;
  Q.push({0, 0});
  bool used[8][8] = {false};
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w)
        continue;
      if (N[ny][nx] == nc)
        Q.push({ny, nx});
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(N, count + 1, i, res);
  else
    on(N, count + 1, Col, res);
}
void solve() {
  int res = 0;
  P V(h);
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      int t;
      cin >> t;
      V[y].push_back(t);
    }
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      on(V, 0, i, res);
  }
  cout << res << endl;
}
int main() {
  while (cin >> h >> w >> Col) {
    if (w == 0)
      break;
    solve();
  }
  return 0;
}