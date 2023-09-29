#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX_SIZE = 8;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

typedef vector<vector<int>> Grid;

int w, h, Col;
int res;
Grid V;
Grid temp(MAX_SIZE, vector<int>(MAX_SIZE));
bool used[MAX_SIZE][MAX_SIZE];
int tres;

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

void on(Grid N, int count, int c) {
  if (count == 5) {
    temp = N;
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }

  int nc = N[0][0];
  queue<pair<int, int>> Q;
  memset(used, false, sizeof(used));
  Q.push(make_pair(0, 0));
  while (!Q.empty()) {
    auto now = Q.front();
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