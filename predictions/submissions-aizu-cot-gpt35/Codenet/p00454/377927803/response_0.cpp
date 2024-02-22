#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

constexpr int inf = 1e9;

int w, h;
int n;
std::vector<int> x1, x2, y1, y2;
std::vector<std::vector<bool>> fld;
std::vector<int> dx = {-1, 0, 1, 0};
std::vector<int> dy = {0, -1, 0, 1};

int compress(std::vector<int>& x1, std::vector<int>& x2, int w) {
  std::unordered_set<int> xs;
  for (int i = 0; i < n; ++i) {
    for (int d = -1; d <= 1; ++d) {
      int tx1 = x1[i] + d, tx2 = x2[i] + d;
      if (0 <= tx1 && tx1 <= w)
        xs.insert(tx1);
      if (0 <= tx2 && tx2 <= w)
        xs.insert(tx2);
    }
  }
  std::vector<int> sorted_xs(xs.begin(), xs.end());
  std::sort(sorted_xs.begin(), sorted_xs.end());
  for (int i = 0; i < n; ++i) {
    x1[i] = std::lower_bound(sorted_xs.begin(), sorted_xs.end(), x1[i]) - sorted_xs.begin();
    x2[i] = std::lower_bound(sorted_xs.begin(), sorted_xs.end(), x2[i]) - sorted_xs.begin();
  }
  return sorted_xs.size();
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  while (std::cin >> w >> h, w) {
    std::cin >> n;
    x1.resize(n);
    x2.resize(n);
    y1.resize(n);
    y2.resize(n);
    fld.assign(6 * w + 2, std::vector<bool>(6 * h + 2, false));

    for (int i = 0; i < n; ++i) {
      std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    w = compress(x1, x2, w);
    h = compress(y1, y2, h);

    for (int i = 0; i < n; ++i) {
      for (int y = y1[i]; y <= y2[i] - 1; ++y) {
        for (int x = x1[i]; x <= x2[i] - 1; ++x) {
          fld[y][x] = true;
        }
      }
    }

    int ans = 0;
    for (int y = 0; y < h - 1; ++y) {
      for (int x = 0; x < w - 1; ++x) {
        if (fld[y][x])
          continue;

        ans++;
        std::queue<std::pair<int, int>> q;
        q.emplace(y, x);

        while (!q.empty()) {
          std::pair<int, int> p = q.front();
          q.pop();

          for (int i = 0; i < 4; ++i) {
            int ny = p.first + dy[i], nx = p.second + dx[i];
            if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny][nx])
              continue;
            fld[ny][nx] = true;
            q.emplace(ny, nx);
          }
        }
      }
    }

    std::cout << ans << "\n";
  }

  return 0;
}