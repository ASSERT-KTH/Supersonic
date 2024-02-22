#include <iostream>
#include <string.h>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P N;
int tres = 0;
void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (N[y][x] == Col) {
    tres++;
    N[y][x] = 0;
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
  int nc = N[0][0];
  N[0][0] = c;
  for (int r = 0; r < 4; r++) {
    int ny = dy[r], nx = dx[r];
    if (ny < 0 || nx < 0 || ny >= h || nx >= w)
      continue;
    if (N[ny][nx] == nc)
      on(count + 1, c);
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(count + 1, i);
  else
    on(count + 1, Col);
}
void solve() {
  res = 0;
  N.clear();
  N.resize(h);
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      cin >> N[y][x];
    }
  for (int i = 1; i <= 6; i++) {
    if (N[0][0] != i)
      on(0, i);
  }
  cout << res << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> h >> w >> Col) {
    if (w == 0)
      break;
    solve();
  }
  return 0;
}