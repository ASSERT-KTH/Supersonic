#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct po {
  int lx, ly, rx, ry;
};

int w, h;
char mp[2][51][51];  // Changed from string to char array
bool visited[51][51][51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y, int i) {
  int nx = x + dx[i], ny = y + dy[i];
  if (nx < 0 || ny < 0 || nx >= w || ny >= h || mp[i][ny][nx] == '#') 
    return false;
  return true;
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
      int nlx = isValid(t.lx, t.ly, 0) ? t.lx + dx[i] : t.lx;
      int nly = isValid(t.lx, t.ly, 0) ? t.ly + dy[i] : t.ly;
      int nrx = isValid(t.rx, t.ry, 1) ? t.rx - dx[i] : t.rx;
      int nry = isValid(t.rx, t.ry, 1) ? t.ry + dy[i] : t.ry;
      if (!isValid(t.lx, t.ly, 0)) flg++;
      if (!isValid(t.rx, t.ry, 1)) flg++;
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
      for (int j = 0; j < w; j++)
        cin >> mp[0][i][j] >> mp[1][i][j];  // Read into char array instead of string
    int lx, ly, rx, ry;
    bool foundL = false, foundR = false;
    for (int i = 0; i < h && !(foundL && foundR); i++)
      for (int j = 0; j < w && !(foundL && foundR); j++) {
        if (mp[0][i][j] == 'L')
          lx = j, ly = i, foundL = true;
        if (mp[1][i][j] == 'R')
          rx = j, ry = i, foundR = true;
      }
    fill_n(&visited[0][0][0][0], 51*51*51*51, false);  // Using fill_n to replace memset
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}