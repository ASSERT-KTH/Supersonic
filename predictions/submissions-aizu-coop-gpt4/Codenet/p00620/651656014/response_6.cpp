#include <iostream>
#include <queue>
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
priority_queue<SP> starts;
bool dfs(int cur, int sum, int x, int y) {
  if (cur == sum) {
    sum = 0;
    starts.pop();
    if (starts.empty()) {
      return true;
    }
    x = starts.top().second.second;
    y = starts.top().second.first;
    cur = starts.top().first;
  } else if (cur < sum) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
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
  while(!starts.empty())
    starts.pop();
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
  bool ret = false;
  if (sum == 0) {
    if (starts.size() == 1) {
      ret = true;
    } else {
      int cur = starts.top().first;
      ret = dfs(cur, 0, starts.top().second.second, starts.top().second.first);
    }
  }
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