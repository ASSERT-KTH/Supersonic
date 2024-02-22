#include <iostream>
#include <queue>
using namespace std;

struct po {
  int lx, ly, rx, ry;
};

int w, h;
char mp[2][51][51];
bool visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push({lx, ly, rx, ry});

  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2)
      return true;
    if (visited[t.ly][t.lx] || cnt == 1)
      continue;
    visited[t.ly][t.lx] = true;

    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
        nlx = t.lx;
        nly = t.ly;
        flg++;
      }
      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
        nrx = t.rx;
        nry = t.ry;
        flg++;
      }
      if (flg == 2)
        continue;

      Q.push({nlx, nly, nrx, nry});
    }
  }
  return false;
}

int main() {
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mp[0][i][j];
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mp[1][i][j];
      }
    }

    int lx, ly, rx, ry;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L') {
          lx = j;
          ly = i;
        }
        if (mp[1][i][j] == 'R') {
          rx = j;
          ry = i;
        }
      }
    }

    memset(visited, false, sizeof(visited));
    if (bfs(lx, ly, rx, ry))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }

  return 0;
}