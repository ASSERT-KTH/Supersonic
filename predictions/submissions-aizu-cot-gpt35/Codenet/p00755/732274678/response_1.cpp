#include <iostream>
#include <vector>
using namespace std;

int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;

void calc(P& temp, int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y][x] == Col) {
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(temp, y + dy[r], x + dx[r]);
  }
}

void on(P& N, int count, int c) {
  if (count == 5) {
    P temp = N;
    int tres = 0;
    calc(temp, 0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  bool used[8][8] = {false};
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (used[y][x])
        continue;
      used[y][x] = true;
      N[y][x] = c;
      for (int r = 0; r < 4; r++) {
        int ny = y + dy[r], nx = x + dx[r];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
          continue;
        if (N[ny][nx] == nc)
          used[ny][nx] = true;
      }
    }
  }
  if (count != 4)
    on(N, count + 1, Col);
  else
    on(N, count + 1, Col);
}

void solve() {
  res = 0;
  V.resize(h);
  for (int y = 0; y < h; y++) {
    V[y].resize(w);
    for (int x = 0; x < w; x++) {
      cin >> V[y][x];
    }
  }
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