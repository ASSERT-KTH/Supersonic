#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P temp;
int tres = 0;

void calc(int y, int x) {
  stack<C> s;
  s.push(make_pair(y,x));
  while (!s.empty()) {
    C p = s.top(); s.pop();
    y = p.first; x = p.second;
    if (y < 0 || x < 0 || x >= w || y >= h || temp[y][x] != Col) continue;
    tres++;
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      s.push(make_pair(y + dy[r], x + dx[r]));
  }
}

void on(P N, int count, int c) {
  if (count == 5) {
    temp = N;
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  stack<C> S;
  S.push(make_pair(0, 0));
  bool used[8][8];
  memset(used, false, sizeof(used));
  int tres = 0;
  while (!S.empty()) {
    C now = S.top(); S.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w)
        continue;
      if (N[ny][nx] == nc)
        S.push(make_pair(ny, nx));
    }
  }
  for (int i = 1; i <= 6; i++)
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