#include <iostream>
using namespace std;
int w, h, Col, V[8][8], dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, res, used[8][8], timestamp, qx[64], qy[64];

void calc(int y, int x) {
  int qn = 1, tres = 0;
  qx[0] = x, qy[0] = y;
  while (qn) {
    --qn;
    x = qx[qn], y = qy[qn];
    if (y < 0 || x < 0 || x >= w || y >= h || V[y][x] != Col) continue;
    tres++;
    V[y][x] = 0;
    for (int r = 0; r < 4; r++) qx[qn] = x + dx[r], qy[qn] = y + dy[r], ++qn;
  }
  res = max(res, tres);
}

void on(int count, int c) {
  if (count == 5) {
    calc(0, 0);
    return;
  }
  int nc = V[0][0], qn = 1, changes[64];
  qx[0] = 0, qy[0] = 0;
  ++timestamp;
  while (qn) {
    --qn;
    int x = qx[qn], y = qy[qn];
    if (used[y][x] == timestamp) continue;
    used[y][x] = timestamp;
    V[y][x] = c;
    changes[qn] = y * w + x;
    for (int r = 0; r < 4; r++) {
      int nx = x + dx[r], ny = y + dy[r];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w || V[ny][nx] != nc) continue;
      qx[qn] = nx, qy[qn] = ny, ++qn;
    }
  }
  if (count != 4)
    for (int i = 1; i <= 6; i++) on(count + 1, i);
  else
    on(count + 1, Col);
  for (int i = 0; i < qn; i++) V[changes[i] / w][changes[i] % w] = nc;
}

void solve() {
  res = 0;
  for (int y = 0; y < h; y++)
    for (int x = 0; x < w; x++) cin >> V[y][x];
  for (int i = 1; i <= 6; i++) on(0, i);
  cout << res << endl;
}

int main() {
  while (cin >> h >> w >> Col) {
    if (w == 0) break;
    solve();
  }
  return 0;
}