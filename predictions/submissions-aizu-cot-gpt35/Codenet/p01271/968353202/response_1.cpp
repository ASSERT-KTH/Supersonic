#include <iostream>
#include <queue>
#include <vector>

class Position {
private:
  int lx, ly, rx, ry;

public:
  Position(int lx, int ly, int rx, int ry)
      : lx(lx), ly(ly), rx(rx), ry(ry) {}

  int getLX() const { return lx; }
  int getLY() const { return ly; }
  int getRX() const { return rx; }
  int getRY() const { return ry; }
};

bool bfs(const std::vector<std::vector<std::string>> &mp,
         std::vector<std::vector<std::vector<std::vector<bool>>>> &visited,
         const Position &start) {
  int w = mp[0][0].size();
  int h = mp[0].size();

  std::queue<Position> Q;
  Q.push(start);

  while (!Q.empty()) {
    const Position &t = Q.front();
    Q.pop();

    int cnt = (mp[0][t.getLY()][t.getLX()] == "%") +
              (mp[1][t.getRY()][t.getRX()] == "%");

    if (cnt == 2)
      return true;

    if (visited[t.getLX()][t.getLY()][t.getRX()][t.getRY()] || cnt == 1)
      continue;

    visited[t.getLX()][t.getLY()][t.getRX()][t.getRY()] = true;

    for (int i = 0; i < 4; i++) {
      int flg = 0;
      int nlx = t.getLX() + dx[i], nly = t.getLY() + dy[i];
      int nrx = t.getRX() - dx[i], nry = t.getRY() + dy[i];

      if (nlx < 0 || nly < 0 || nlx >= w || nly >= h ||
          mp[0][nly][nlx] == "#")
        nlx = t.getLX(), nly = t.getLY(), flg++;

      if (nrx < 0 || nry < 0 || nrx >= w || nry >= h ||
          mp[1][nry][nrx] == "#")
        nrx = t.getRX(), nry = t.getRY(), flg++;

      if (flg == 2)
        continue;

      Q.push(Position(nlx, nly, nrx, nry));
    }
  }

  return false;
}

int main() {
  while (true) {
    int w, h;
    std::cin >> w >> h;

    if (w == 0 && h == 0)
      break;

    std::vector<std::vector<std::string>> mp(2, std::vector<std::string>(h));
    for (std::size_t i = 0; i < h; i++)
      std::cin >> mp[0][i] >> mp[1][i];

    Position start(0, 0, 0, 0);
    for (std::size_t i = 0; i < h; i++) {
      for (std::size_t j = 0; j < w; j++) {
        if (mp[0][i][j] == 'L')
          start = Position(j, i, start.getRX(), start.getRY());
        if (mp[1][i][j] == 'R')
          start = Position(start.getLX(), start.getLY(), j, i);
      }
    }

    std::vector<std::vector<std::vector<std::vector<bool>>>> visited(
        w, std::vector<std::vector<std::vector<bool>>>(
               h, std::vector<std::vector<bool>>(w, std::vector<bool>(h))));

    if (bfs(mp, visited, start))
      std::cout << "Yes" << std::endl;
    else
      std::cout << "No" << std::endl;
  }

  return 0;
}