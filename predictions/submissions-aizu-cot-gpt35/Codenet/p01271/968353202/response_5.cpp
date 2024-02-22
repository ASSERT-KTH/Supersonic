#include <iostream>
#include <vector>
#include <deque>

struct po {
  int lx, ly, rx, ry;
};

int w, h;
std::vector<std::vector<std::string>> mp;
std::vector<std::vector<std::vector<std::vector<bool>>>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int lx, int ly, int rx, int ry) {
  std::deque<po> Q;
  Q.push_back((po){lx, ly, rx, ry});

  while (!Q.empty()) {
    po t = Q.front();
    Q.pop_front();
    int cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');

    if (cnt == 2)
      return true;

    if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1)
      continue;

    visited[t.lx][t.ly][t.rx][t.ry] = true;

    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.lx + dx[i], nly = t.ly + dy[i];
      int nrx = t.rx - dx[i], nry = t.ry + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
        nlx = t.lx, nly = t.ly, flg++;

      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#')
        nrx = t.rx, nry = t.ry, flg++;

      if (flg == 2)
        continue;

      Q.push_back((po){nlx, nly, nrx, nry});
    }
  }

  return false;
}

int main() {
  while (1) {
    std::cin >> w >> h;
    if (!w && !h)
      break;

    mp.resize(2, std::vector<std::string>(h));
    visited.resize(w, std::vector<std::vector<std::vector<bool>>>(h, std::vector<std::vector<bool>>(w, std::vector<bool>(h, false))));

    for (int i = 0; i < h; i++)
      std::cin >> mp[0][i] >> mp[1][i];

    int lx, ly, rx, ry;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L')
          lx = j, ly = i;
        if (mp[1][i][j] == 'R')
          rx = j, ry = i;
      }
    }

    if (bfs(lx, ly, rx, ry))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }

  return 0;
}