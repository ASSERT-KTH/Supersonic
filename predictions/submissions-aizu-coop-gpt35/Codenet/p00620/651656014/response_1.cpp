#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;
typedef std::pair<int, int> Point;
typedef std::pair<int, Point> SP;
typedef std::vector<std::vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void solve() {
  int n;
  std::cin >> n;

  if (n == 0)
    return;

  Mat mat(n, std::vector<int>(n));
  std::vector<bool> visited(n * n, false);
  std::vector<SP> starts;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      std::cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        visited[i * n + j] = true;
        starts.push_back(SP(a, Point(i, j)));
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
    std::sort(starts.begin(), starts.end(), [](const SP& a, const SP& b) {
      return a.first > b.first;
    });

    std::vector<int> stack;
    std::vector<int> cur(starts.size(), 0); // Current position for each start point

    stack.push_back(0); // Push the first start point into the stack

    while (!stack.empty()) {
      int idx = stack.back(); // Get the index of the current start point
      int x = starts[idx].second.second;
      int y = starts[idx].second.first;

      if (starts[idx].first == cur[idx]) {
        stack.pop_back(); // Pop the current start point from the stack
        if (idx + 1 >= starts.size()) {
          ret = true;
          break; // All start points are covered
        }
        cur[idx + 1] = 0; // Reset the position for the next start point
        stack.push_back(idx + 1); // Push the next start point into the stack
        continue;
      }

      int nx = x + dx[cur[idx]];
      int ny = y + dy[cur[idx]];

      if (0 <= nx && nx < n && 0 <= ny && ny < n && !visited[ny * n + nx]) {
        visited[ny * n + nx] = true;
        cur[idx]++;
        stack.push_back(idx); // Push the current start point back into the stack
        stack.push_back(starts.size()); // Push a sentinel value to indicate a new start point
      } else {
        cur[idx]++; // Move to the next direction
      }
    }
  }

  std::cout << (ret ? "YES" : "NO") << std::endl;
}

int main() {
  while (true) {
    solve();
  }
  return 0;
}