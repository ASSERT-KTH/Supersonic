#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Mat;
typedef pair<int, int> Point;
typedef pair<int, Point> SP;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n;
Mat mat;
vector<vector<bool>> used;
vector<SP> starts(0);

bool dfs(int cur, int sum, int x, int y, int targetSum) {
  if (sum == targetSum) {
    cur++;
    sum = 0;
    if (cur >= starts.size()) {
      return true;
    }
    x = starts[cur].second.second;
    y = starts[cur].second.first;
  } else if (sum > targetSum) {
    return false;
  }
  
  for (auto& d : dx) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny, targetSum))
        return true;
      used[ny][nx] = false;
    }
  }
  
  return false;
}

void solve() {
  mat = Mat(n, vector<int>(n));
  used = vector<vector<bool>>(n, vector<bool>(n, false));
  starts.clear();
  int sum = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        used[i][j] = true;
        starts.push_back(SP(a, Point(i, j)));
      }
      mat[i][j] = a;
    }
  }
  
  int targetSum = 0;
  bool ret = false;
  
  if (sum == 0 && starts.size() != 1) {
    sort(starts.begin(), starts.end(), greater<SP>());
    targetSum = starts[0].first;
    ret = dfs(0, 0, starts[0].second.second, starts[0].second.first, targetSum);
  }
  
  cout << (ret ? "YES" : "NO") << endl;
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solve();
  }
}