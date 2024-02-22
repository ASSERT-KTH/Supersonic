#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> C;
typedef vector<vector<int>> P;
P V, G;
int w, h, Col, res, tres;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h || G[y][x] != Col)
    return;
  tres++;
  G[y][x] = 0;
  for (int r = 0; r < 4; r++)
    calc(y + dy[r], x + dx[r]);
}

void on(int count, int c) {
  if (count == 5) {
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = G[0][0];
  queue<C> Q;
  Q.push(make_pair(0, 0));
  bool used[8][8] = {false};
  int tres = 0;
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    G[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w || used[ny][nx] || G[ny][nx] != nc)
        continue;
      used[ny][nx] = true;
      Q.push(make_pair(ny, nx));
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++) {
      on(count + 1, i);
      G = V; // revert the changes
    }
  else {
    on(count + 1, Col);
    G = V; // revert the changes
  }
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
  G = V; // copy the initial grid
  for (int i = 1; i <= 6; i++) {
    if (G[0][0] != i)
      on(0, i);
    G = V; // revert the changes
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