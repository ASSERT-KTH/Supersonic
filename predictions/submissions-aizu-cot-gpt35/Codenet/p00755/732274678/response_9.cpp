#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_H = 8;
const int MAX_W = 8;
const int MAX_COLORS = 6;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

using Coord = pair<int, int>;
using Grid = vector<vector<int>>;

Grid V;
Grid temp;
int res;

void calc(Grid& temp, int y, int x, int Col) {
  if (y < 0 || x < 0 || x >= temp[0].size() || y >= temp.size())
    return;
  if (temp[y][x] == Col) {
    temp[y][x] = 0;
    ++res;
    for (int r = 0; r < 4; ++r)
      calc(temp, y + dy[r], x + dx[r], Col);
  }
}

void on(Grid& N, int count, int c) {
  if (count == 5) {
    temp = N;
    res = 0;
    calc(temp, 0, 0, c);
    res = max(res, res);
    return;
  }
  const int nc = N[0][0];
  queue<Coord> Q;
  Q.push(make_pair(0, 0));
  bool used[MAX_H * MAX_W] = {false};
  while (!Q.empty()) {
    Coord& now = Q.front();
    Q.pop();
    const int index = now.first * MAX_W + now.second;
    if (used[index])
      continue;
    used[index] = true;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; ++r) {
      const int ny = now.first + dy[r];
      const int nx = now.second + dx[r];
      if (ny < 0 || nx < 0 || ny >= N.size() || nx >= N[0].size())
        continue;
      if (N[ny][nx] == nc)
        Q.push(make_pair(ny, nx));
    }
  }
  if (count != 4) {
    for (int i = 1; i <= MAX_COLORS; ++i)
      on(N, count + 1, i);
  } else {
    on(N, count + 1, Col);
  }
}

void solve() {
  res = 0;
  for (int y = 0; y < V.size(); ++y)
    for (int x = 0; x < V[y].size(); ++x) {
      int t;
      cin >> t;
      V[y][x] = t;
    }
  for (int i = 1; i <= MAX_COLORS; ++i) {
    if (V[0][0] != i)
      on(V, 0, i);
  }
  cout << res << endl;
}

int main() {
  int h, w, Col;
  while (cin >> h >> w >> Col) {
    if (w == 0)
      break;
    V.resize(h, vector<int>(w));
    solve();
  }
  return 0;
}