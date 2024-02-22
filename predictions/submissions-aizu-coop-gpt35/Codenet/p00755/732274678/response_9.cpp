#include <iostream>
#include <queue>
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
int tres = 0;

void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (V[y][x] == Col) {
    tres++;
    V[y][x] = 0;
    
    // Stack-based iteration instead of recursion
    stack<C> s;
    s.push(make_pair(y, x));
    while (!s.empty()) {
      C now = s.top();
      s.pop();
      
      for (int r = 0; r < 4; r++) {
        int ny = now.first + dy[r], nx = now.second + dx[r];
        if (ny < 0 || nx < 0 || ny >= h || nx >= w)
          continue;
        if (V[ny][nx] == Col) {
          s.push(make_pair(ny, nx));
          V[ny][nx] = 0;
          tres++;
        }
      }
    }
  }
}

void on(P& N, int count, int c) {
  if (count == 5) {
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
    for (int i = c; i <= 6; i++) // Start from c instead of 1
      on(N, count + 1, i);
  else
    on(N, count + 1, Col);
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