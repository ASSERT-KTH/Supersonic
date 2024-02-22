#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> C;
typedef vector<vector<int>> P;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int calc(P& temp, int y, int x, int Col) {
  if (y < 0 || x < 0 || x >= temp[0].size() || y >= temp.size())
    return 0;
  if (temp[y][x] != Col)
    return 0;
  int tres = 1;
  temp[y][x] = 0;
  for (int r = 0; r < 4; r++)
    tres += calc(temp, y + dy[r], x + dx[r], Col);
  return tres;
}

void on(P& N, int count, int c, int Col, int& res) {
  if (count == 5) {
    P temp = N;
    int tres = calc(temp, 0, 0, Col);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  queue<C> Q;
  Q.emplace(0, 0);
  bool used[8][8] = {false};
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= N.size() || nx >= N[0].size())
        continue;
      if (N[ny][nx] == nc)
        Q.emplace(ny, nx);
    }
  }
  for (int i = 1; i <= 6; i++)
    on(N, count + 1, i, Col, res);
}

void solve() {
  int h, w, Col;
  cin >> h >> w >> Col;
  if (w == 0)
    return;
  int res = 0;
  P V(h, vector<int>(w));
  for (auto& row : V)
    for (auto& cell : row)
      cin >> cell;
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      on(V, 0, i, Col, res);
  }
  cout << res << endl;
}

int main() {
  while (true) {
    solve();
  }
  return 0;
}