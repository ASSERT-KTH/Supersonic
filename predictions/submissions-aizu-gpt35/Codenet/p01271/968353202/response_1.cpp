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

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push((po){lx, ly, rx, ry});

  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
    if (cnt == 2) {
      return true;
    }
    if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1) {
      continue;
    }
    visited[t.lx][t.ly][t.rx][t.ry] = true;

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
      if (flg == 2) {
        continue;
      }
      Q.push((po){nlx, nly, nrx, nry});
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    cin >> w >> h;
    if (!w && !h) {
      break;
    }

    for (int i = 0; i < h; i++) {
      cin >> mp[0][i] >> mp[1][i];
    }

    int lx = 0, ly = 0, rx = 0, ry = 0;
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
    if (bfs(lx, ly, rx, ry)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}