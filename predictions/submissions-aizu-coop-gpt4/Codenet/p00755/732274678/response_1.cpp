#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
int tres = 0;
void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (V[y][x] == Col) {
    tres++;
    V[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(y + dy[r], x + dx[r]);
  }
}
void on(int count, int c) {
  if (count == 5) {
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = V[0][0];
  vector<C> changed;
  V[0][0] = c;
  changed.push_back(make_pair(0, 0));
  for (int r = 0; r < 4; r++) {
    int ny = 0 + dy[r], nx = 0 + dx[r];
    if (ny < 0 || nx < 0 || ny >= h || nx >= w)
      continue;
    if (V[ny][nx] == nc) {
      V[ny][nx] = c;
      changed.push_back(make_pair(ny, nx));
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(count + 1, i);
  else
    on(count + 1, Col);
  for (C cell : changed)
    V[cell.first][cell.second] = nc;
}
void solve() {
  res = 0;
  V.clear();
  V.resize(h);
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      int t;
      cin >> t;
      V[y].push_back(t);
    }
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      on(0, i);
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