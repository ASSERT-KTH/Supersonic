#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> Point;
typedef pair<int, Point> SP;
typedef vector<vector<int>> Mat;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
Mat mat;
vector<vector<bool>> used;
vector<SP> starts;

bool dfs(int cur, int sum, int x, int y) {
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
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny))
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
      cin >> mat[i][j];
      sum += mat[i][j];
      if (mat[i][j] < 0) {
        mat[i][j] *= -1;
        used[i][j] = true;
        starts.emplace_back(mat[i][j], Point(i, j));
      }
    }
  }
  if (sum != 0) {
    cout << "NO" << endl;
  } else if (starts.size() == 1) {
    cout << "YES" << endl;
  } else {
    sort(starts.begin(), starts.end(), greater<SP>());
    cout << (dfs(0, 0, starts[0].second.second, starts[0].second.first) ? "YES" : "NO") << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> n && n != 0) {
    solve();
  }
  return 0;
}