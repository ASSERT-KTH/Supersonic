#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef int P[8][8];
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P temp;
int tres = 0;
void calc(int y, int x) {
  queue<C> q;
  q.push({y, x});
  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();
    if (cy < 0 || cx < 0 || cx >= w || cy >= h || temp[cy][cx] != Col)
      continue;
    tres++;
    temp[cy][cx] = 0;
    for (int r = 0; r < 4; r++)
      q.push({cy + dy[r], cx + dx[r]});
  }
}
void on(P &N, int count, int c) {
  if (count == 5) {
    memcpy(temp, N, sizeof(temp));
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  queue<C> Q;
  Q.push(make_pair(0, 0));
  bool used[8][8];
  memset(used, false, sizeof(used));
  int tres = 0;
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
        Q.push(make_pair(ny, nx));
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++)
      on(N, count + 1, i);
  else
    on(N, count + 1, Col);
}
void solve() {
  res = 0;
  memset(V, 0, sizeof(V));
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      cin >> V[y][x];
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