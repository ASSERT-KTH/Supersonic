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
int dp[8][6][7]; // Dynamic programming array

void calc(int y, int x, P& temp) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y][x] == Col) {
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(y + dy[r], x + dx[r], temp);
  }
}

int on(P& N, int count, int c, int dp[8][6][7]) {
  if (count == 5) {
    P temp = N;
    int tres = 0;
    calc(0, 0, temp);
    return tres;
  }
  if (dp[N[0][0]][count][c] != -1) {
    return dp[N[0][0]][count][c]; // Return precomputed result
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
  int result;
  if (count != 4) {
    result = 0;
    for (int i = 1; i <= 6; i++)
      result = max(result, on(N, count + 1, i, dp));
  } else {
    result = on(N, count + 1, Col, dp);
  }
  dp[N[0][0]][count][c] = result; // Store computed result
  return result;
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
  memset(dp, -1, sizeof(dp)); // Initialize dp array
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      res = max(res, on(V, 0, i, dp));
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