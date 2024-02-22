#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> Point;
typedef pair<int, Point> SP;
typedef vector<vector<int>> Mat;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;

bool dfs(int cur, int sum, int x, int y, Mat& mat, vector<vector<bool>>& used, priority_queue<SP>& starts) {
  if (starts.top().first == sum) {
    starts.pop();
    sum = 0;
    if (starts.empty()) {
      return true;
    }
    x = starts.top().second.second;
    y = starts.top().second.first;
  } else if (starts.top().first < sum) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny, mat, used, starts))
        return true;
      used[ny][nx] = false;
    }
  }
  return false;
}

void solve() {
  Mat mat(n, vector<int>(n));
  vector<vector<bool>> used(n, vector<bool>(n, false));
  priority_queue<SP> starts;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        used[i][j] = true;
        starts.push(SP(a, Point(i, j)));
      }
      mat[i][j] = a;
    }
  }
  bool ret = sum == 0 && (starts.size() == 1 || dfs(0, 0, starts.top().second.second, starts.top().second.first, mat, used, starts));
  cout << (ret ? "YES" : "NO") << endl;
  return;
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solve();
  }
  return 0;
}