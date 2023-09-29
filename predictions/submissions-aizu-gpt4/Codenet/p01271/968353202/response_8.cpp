#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct po {
  int lx, ly, rx, ry;
};
int w, h;
string mp[2][51];
bool visited[51][51][51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
inline bool valid(int x, int y) { return x >= 0 && y >= 0 && x < w && y < h; }
bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push({lx, ly, rx, ry});
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2)
      return true;
    if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1)
      continue;
    visited[t.lx][t.ly][t.rx][t.ry] = true;
    for (int i = 0; i < 4; ++i) {
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      if (!valid(nlx, nly) || mp[0][nly][nlx] == '#') nlx = t.lx, nly = t.ly;
      int nrx = t.rx - dx[i], nry = t.ry - dy[i];
      if (!valid(nrx, nry) || mp[1][nry][nrx] == '#') nrx = t.rx, nry = t.ry;
      if (!(nlx == t.lx && nly == t.ly && nrx == t.rx && nry == t.ry))
        Q.push({nlx, nly, nrx, nry});
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> w >> h && w && h) {
    for (int i = 0; i < h; ++i)
      cin >> mp[0][i] >> mp[1][i];
    int lx, ly, rx, ry;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        if (mp[0][i][j] == 'L')
          lx = j, ly = i;
        if (mp[1][i][j] == 'R')
          rx = j, ry = i;
      }
    memset(visited, 0, sizeof(visited));
    cout << (bfs(lx, ly, rx, ry) ? "Yes\n" : "No\n");
  }
  return 0;
}