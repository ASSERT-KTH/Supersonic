#include <iostream>
#include <vector>
using namespace std;
int w, h, Col;
typedef vector<vector<int>> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P temp;
int tres = 0;
void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y][x] == Col) {
    tres++;
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(y + dy[r], x + dx[r]);
  }
}
void on(P& N, int count, int c) {
  if (count == 5) {
    temp = N;
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  N[0][0] = c;
  for (int x = 1; x < w; ++x) {
    if (N[0][x] == nc) N[0][x] = c;
    else break;
  }
  for (int y = 1; y < h; ++y) {
    if (N[y][0] == nc) N[y][0] = c;
    else break;
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(N, count + 1, i);
  else
    on(N, count + 1, Col);
}
void solve() {
  res = 0;
  V.clear();
  V.resize(h, vector<int>(w));
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++)
      cin >> V[y][x];
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      on(V, 0, i);
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