#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<std::string>> mp;
std::vector<std::vector<bool>> visited;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool bfs(const std::pair<int, int>& start, const std::pair<int, int>& end) {
  std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> Q;
  Q.push(std::make_pair(start, end));

  while (!Q.empty()) {
    auto t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.first.second][t.first.first] == '%') + (mp[1][t.second.second][t.second.first] == '%');
    if (cnt == 2)
      return true;

    if (visited[t.first.first][t.first.second] || cnt == 1)
      continue;

    visited[t.first.first][t.first.second] = true;

    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.first.first + dx[i], nly = t.first.second + dy[i];
      int nrx = t.second.first - dx[i], nry = t.second.second + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= mp[0][0].size() || nly >= mp[0].size() || mp[0][nly][nlx] == '#')
        nlx = t.first.first, nly = t.first.second, flg++;

      if (nrx < 0 || nry < 0 || nrx >= mp[1][0].size() || nry >= mp[1].size() || mp[1][nry][nrx] == '#')
        nrx = t.second.first, nry = t.second.second, flg++;

      if (flg == 2)
        continue;

      Q.push(std::make_pair(std::make_pair(nlx, nly), std::make_pair(nrx, nry)));
    }
  }

  return false;
}

int main() {
  int w, h;
  
  while (std::cin >> w >> h) {
    if (!w && !h)
      break;

    mp.resize(2, std::vector<std::string>(h));
    visited.assign(w, std::vector<bool>(h, false));

    for (int i = 0; i < h; i++)
      std::cin >> mp[0][i] >> mp[1][i];

    std::pair<int, int> start, end;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L')
          start = std::make_pair(j, i);
        if (mp[1][i][j] == 'R')
          end = std::make_pair(j, i);
      }
    }

    if (bfs(start, end))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }

  return 0;
}