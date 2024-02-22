#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool dfs(const Mat& mat, vector<vector<bool>>& used, const vector<pair<int, pair<int, int>>>& starts) {
  int n = mat.size();
  vector<pair<int, pair<int, int>>> stack;
  stack.reserve(starts.size());
  int cur = 0;
  int sum = 0;
  int x = starts[0].second.second;
  int y = starts[0].second.first;

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
      return false;
    }
    
    bool found = false;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
        used[ny][nx] = true;
        stack.emplace_back(cur, make_pair(nx, ny));
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
      cur = stack.back().first;
      x = stack.back().second.first;
      y = stack.back().second.second;
      sum -= mat[y][x];
      used[y][x] = false;
      stack.pop_back();
    }
  }
}

void solve() {
  int n;
  cin >> n;

  if (n == 0) {
    return;
  }

  Mat mat(n, vector<int>(n));
  vector<vector<bool>> used(n, vector<bool>(n, false));
  vector<pair<int, pair<int, int>>> starts;
  starts.reserve(n * n);

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        used[i][j] = true;
        starts.emplace_back(a, make_pair(i, j));
      }
      mat[i][j] = a;
    }
  }

  bool ret = false;
  if (sum == 0 && starts.size() > 1) {
    sort(starts.begin(), starts.end(), greater<pair<int, pair<int, int>>>());
    ret = dfs(mat, used, starts);
  }

  cout << (ret ? "YES" : "NO") << endl;
}

int main() {
  int n;
  while (cin >> n && n != 0) {
    solve();
  }
  return 0;
}