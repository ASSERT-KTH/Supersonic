#include <iostream>
#include <queue>
#include <vector>

int w, h, Col;
typedef std::pair<int, int> C;
typedef std::vector<int> P;
std::vector<P> V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;

void calc(int y, int x, std::vector<P>& temp) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y][x] == Col) {
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(y + dy[r], x + dx[r], temp);
  }
}

void on(const std::vector<P>& N, int count, int c) {
  if (count == 5) {
    std::vector<P> temp = N;
    int tres = 0;
    calc(0, 0, temp);
    for (int y = 0; y < h; y++)
      for (int x = 0; x < w; x++)
        if (temp[y][x] == 0)
          tres++;
    res = std::max(res, tres);
    return;
  }
  int nc = N[0][0];
  std::queue<C> Q;
  Q.push(std::make_pair(0, 0));
  std::vector<std::vector<bool>> used(h, std::vector<bool>(w, false));
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
        Q.push(std::make_pair(ny, nx));
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
  V.resize(h, P(w));
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) {
      int t;
      std::cin >> t;
      V[y][x] = t;
    }
  for (int i = 1; i <= 6; i++) {
    if (V[0][0] != i)
      on(V, 0, i);
  }
  std::cout << res << std::endl;
}

int main() {
  while (std::cin >> h >> w >> Col) {
    if (w == 0)
      break;
    solve();
  }
  return 0;
}