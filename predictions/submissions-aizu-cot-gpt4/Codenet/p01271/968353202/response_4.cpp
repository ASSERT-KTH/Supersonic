#include <cstring>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppp;
int w, h;
string mp[2][51];
map<ppp, bool> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool bfs(int lx, int ly, int rx, int ry) {
  queue<ppp> Q;
  Q.push({{lx, ly}, {rx, ry}});
  while (!Q.empty()) {
    ppp t = Q.front();
    Q.pop();
    if (visited[t] || (mp[0][t.first.second][t.first.first] == '%' + mp[1][t.second.second][t.second.first] == '%') == 1)
      continue;
    if ((mp[0][t.first.second][t.first.first] == '%' + mp[1][t.second.second][t.second.first] == '%') == 2)
      return true;
    visited[t] = 1;
    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.first.first + dx[i], nly = t.first.second + dy[i];
      int nrx = t.second.first - dx[i], nry = t.second.second + dy[i];
      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
        nlx = t.first.first, nly = t.first.second, flg++;
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#')
        nrx = t.second.first, nry = t.second.second, flg++;
      if (flg == 2)
        continue;
      Q.push({{nlx, nly}, {nrx, nry}});
    }
  }
  return false;
}
int main() {
  while (1) {
    cin >> w >> h;
    if (!w && !h)
      break;
    for (int i = 0; i < h; i++)
      cin >> mp[0][i] >> mp[1][i];
    int lx, ly, rx, ry;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L')
          lx = j, ly = i;
        if (mp[1][i][j] == 'R')
          rx = j, ry = i;
      }
    visited.clear();
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}