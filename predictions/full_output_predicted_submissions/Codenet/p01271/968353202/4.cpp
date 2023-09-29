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
bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push((po){lx, ly, rx, ry});
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2)
      return true;
    if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1)
      continue;
    visited[t.lx][t.ly][t.rx][t.ry] = 1;
    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry + dy[i];
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
        nlx = t.lx, nly = t.ly, flg++;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nlx] ==