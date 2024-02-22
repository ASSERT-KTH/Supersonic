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

bool checkBoundaryAndWall(int &nx, int &ny, int i, int j, int d) {
  nx = i + dx[d], ny = j + dy[d];
  if (nx < 0 || ny < 0 || nx >= w || ny >= h || mp[0][ny][nx] == '#') {
    nx = i, ny = j;
    return true;
  }
  return false;
}

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
      int nlx, nly, nrx, nry;
      flg += checkBoundaryAndWall(nlx, nly, t.lx, t.ly, i);
      flg += checkBoundaryAndWall(nrx, nry, t.rx, t.ry, i);
      if (flg == 2)
        continue;
      Q.push((po){nlx, nly, nrx, nry});
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
    memset(visited, 0, sizeof(visited));
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}