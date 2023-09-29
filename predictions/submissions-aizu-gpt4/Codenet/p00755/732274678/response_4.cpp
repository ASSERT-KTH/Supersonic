#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
constexpr int kMaxSize = 8;
int w, h, Col;
using C = pair<int, int>;
using P = vector<vector<int>>;
P V(kMaxSize, vector<int>(kMaxSize));
array<int, 4> dx = {0, 1, 0, -1};
array<int, 4> dy = {1, 0, -1, 0};
int res;
P temp(kMaxSize, vector<int>(kMaxSize));
int tres = 0;

void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h || temp[y][x] != Col)
    return;

  tres++;
  temp[y][x] = 0;
  for (int r = 0; r < 4; r++)
    calc(y + dy[r], x + dx[r]);
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
  queue<C> Q;
  Q.push(make_pair(0, 0));
  bool used[kMaxSize][kMaxSize] = {{false}};
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w || N[ny][nx] != nc)
        continue;
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
  while (cin >> h >> w >> Col && w != 0)
    solve();
  return 0;
}