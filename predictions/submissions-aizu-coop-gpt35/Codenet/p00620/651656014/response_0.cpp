#include <iostream>
#include <vector>

using Point = std::pair<int, int>;
using SP = std::pair<int, Point>;
using Mat = std::vector<std::vector<int>>;

void solve(int n);

int main() {
  while (true) {
    int n;
    std::cin >> n;
    if (n == 0)
      break;
    solve(n);
  }
  return 0;
}

bool dfs(const Mat& mat, const std::vector<std::vector<bool>>& used, const std::vector<SP>& starts) {
  int n = mat.size();
  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};
  std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
  std::vector<std::pair<int, int>> stack;

  int cur = 0;
  int sum = 0;
  int x = starts[cur].second.second;
  int y = starts[cur].second.first;

  while (true) {
    if (starts[cur].first == sum) {
      cur++;
      sum = 0;
      if (cur >= starts.size()) {
        return true;
      }
      x = starts[cur].second.second;
      y = starts[cur].second.first;
    } else if (starts[cur].first < sum) {
      if (stack.empty())
        return false;

      std::tie(x, y) = stack.back();
      stack.pop_back();
      sum -= mat[y][x];
      visited[y][x] = false;
      continue;
    }

    bool found = false;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[ny][nx] && !used[ny][nx]) {
        visited[ny][nx] = true;
        stack.emplace_back(nx, ny);
        sum += mat[ny][nx];
        found = true;
        break;
      }
    }

    if (!found) {
      if (stack.empty())
        return false;

      std::tie(x, y) = stack.back();
      stack.pop_back();
      sum -= mat[y][x];
      visited[y][x] = false;
    }
  }
}

void solve(int n) {
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
        starts.emplace_back(a, Point(i, j));
      }
      mat[i][j] = a;
    }
  }

  bool ret = false;
  if (sum != 0) {
    ret = false;
  } else if (starts.size() == 1) {
    ret = true;
  } else {
    std::sort(starts.begin(), starts.end(), std::greater<SP>());
    ret = dfs(mat, used, starts);
  }
  std::cout << (ret ? "YES" : "NO") << std::endl;
}