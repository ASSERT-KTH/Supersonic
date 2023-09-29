#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
typedef std::pair<int, int> Point;
typedef std::pair<int, Point> SP;
typedef std::vector<std::vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
Mat mat;
std::vector<std::vector<bool>> used;
std::vector<SP> starts(0);

bool dfs(int cur, int sum, int x, int y) {
  if (starts[cur].first == sum) {
    if (++cur >= starts.size()) return true;
    sum = 0;
    x = starts[cur].second.second;
    y = starts[cur].second.first;
  } else if (starts[cur].first < sum) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny)) return true;
      used[ny][nx] = false;
    }
  }
  return false;
}

void solve() {
  mat = Mat(n, std::vector<int>(n));
  used = std::vector<std::vector<bool>>(n, std::vector<bool>(n, false));
  starts.clear();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> mat[i][j];
      if(mat[i][j] < 0) {
        used[i][j] = true;
        starts.push_back(SP(-mat[i][j], Point(i, j)));
      }
      sum += std::abs(mat[i][j]);
    }
  }
  std::sort(starts.begin(), starts.end(), std::greater<SP>());
  std::cout << ((sum == 0 && starts.size() == 1) || (sum != 0 && dfs(0, 0, starts[0].second.second, starts[0].second.first)) ? "YES" : "NO") << std::endl;
}

int main() {
  while (std::cin >> n && n != 0) solve();
  return 0;
}