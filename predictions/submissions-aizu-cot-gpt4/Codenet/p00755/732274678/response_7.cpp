#include <iostream>
#include <queue>
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
void calc(P &temp, int y, int x) {
  if (temp[y][x] == Col) {
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      if (y + dy[r] >= 0 && x + dx[r] >= 0 && x + dx[r] < w && y + dy[r] < h)
        calc(temp, y + dy[r], x + dx[r]);
  }
}
void on(P N, int count, int c) {
  if (count == 5) {
    int tres = 0;
    calc(N, 0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  queue<C> Q;
  Q.push({0, 0});
  bool used[8][8];
  memset(used, false, sizeof(used));
  C now;
  while (!Q.empty()) {
    now = Q.front();
    Q.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      now.first += dy[r];
      now.second += dx[r];
      if (now.first < 0 || now.second < 0 || now.first >= h || now.second >= w)
        continue;
      if (N[now.first][now.second] == nc)
        Q.push(now);
    }
  }
  for (int i = 1; i <= (count == 4 ? Col : 6); i++)
    on(N, count + 1, i);
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