#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
  int x, y;
};

struct SP {
  int sum;
  Point point;
};

typedef std::vector<std::vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool dfs(const std::vector<SP>& starts, const Mat& mat, std::vector<std::vector<bool>>& used) {
  std::vector<int> path_index(starts.size(), 0);
  std::vector<Point> path_points(starts.size(), {starts[0].point.x, starts[0].point.y});

  int cur = 0;
  int sum = 0;

  while (cur >= 0) {
    int x = path_points[cur].x;
    int y = path_points[cur].y;

    if (starts[cur].sum == sum) {
      cur++;
      sum = 0;
      if (cur >= starts.size()) {
        return true;
      }
      x = starts[cur].point.x;
      y = starts[cur].point.y;
    } else if (starts[cur].sum < sum) {
      cur--;
      sum -= mat[y][x];
      used[y][x] = false;
      continue;
    }

    bool found = false;

    for (int i = path_index[cur]; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < mat[0].size() && 0 <= ny && ny < mat.size() && !used[ny][nx]) {
        used[ny][nx] = true;
        path_index[cur] = i + 1;
        path_points[cur].x = nx;
        path_points[cur].y = ny;
        sum += mat[ny][nx];
        found = true;
        break;
      }
    }

    if (!found) {
      cur--;
      sum -= mat[y][x];
      used[y][x] = false;
    }
  }

  return false;
}

void solve() {
  int n;
  std::cin >> n;

  if (n == 0) return;

  Mat mat(n, std::vector<int>(n));
  std::vector<std::vector<bool>> used(n, std::vector<bool>(n, false));
  std::vector<SP> starts;

  int sum = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      std::cin >> a;
      sum += a;

      if (a < 0) {
        a *= -1;
        used[i][j] = true;
        starts.push_back({a, {j, i}});
      }

      mat[i][j] = a;
    }
  }

  if (sum != 0 || starts.size() == 1) {
    std::cout << "NO" << std::endl;
    return;
  }

  std::sort(starts.begin(), starts.end(), [](const SP& a, const SP& b) { return a.sum > b.sum; });

  std::cout << (dfs(starts, mat, used) ? "YES" : "NO") << std::endl;
}

int main() {
  while (true) {
    solve();
  }
  return 0;
}