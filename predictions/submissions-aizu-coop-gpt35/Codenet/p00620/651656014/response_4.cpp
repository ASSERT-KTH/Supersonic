#include <iostream>
#include <vector>

typedef std::pair<int, int> Point;
typedef std::pair<int, Point> SP;
typedef std::vector<std::vector<int>> Mat;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

bool dfs(const Mat& mat, const std::vector<SP>& starts, std::vector<std::vector<bool>>& used) {
  std::vector<int> stack;
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
    }
    
    bool found = false;
    
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      
      if (0 <= nx && nx < mat.size() && 0 <= ny && ny < mat.size() && !used[ny][nx]) {
        used[ny][nx] = true;
        stack.push_back(ny * mat.size() + nx);
        sum += mat[ny][nx];
        x = nx;
        y = ny;
        found = true;
        break;
      }
    }
    
    if (!found) {
      if (stack.empty()) {
        return false;
      }
      int last = stack.back();
      stack.pop_back();
      sum -= mat[last / mat.size()][last % mat.size()];
      x = last % mat.size();
      y = last / mat.size();
      used[y][x] = false;
    }
  }
}

void solve() {
  int n;
  std::cin >> n;
  
  if (n == 0) {
    return;
  }
  
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
    ret = dfs(mat, starts, used);
  }
  
  std::cout << (ret ? "YES" : "NO") << std::endl;
}

int main() {
  while (true) {
    solve();
  }
  
  return 0;
}