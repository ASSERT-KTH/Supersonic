#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
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
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      sum += mat[ny][nx];
      if (starts[cur].first == sum) {
        if (cur+1 >= starts.size() || dfs(cur+1, 0, starts[cur+1].second.second, starts[cur+1].second.first)) {
          return true;
        }
      } else if (starts[cur].first > sum && dfs(cur, sum, nx, ny)) {
        return true;
      }
      used[ny][nx] = false;
    }
  }
  return false;
}
void solve() {
  mat = Mat(n, vector<int>(n));
  used = vector<vector<bool>>(n, vector<bool>(n, false));
  starts.resize(0);
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
  if (sum != 0) {
    cout << "NO" << endl;
    return;
  }
  if (starts.size() == 1) {
    cout << "YES" << endl;
    return;
  }
  sort(starts.begin(), starts.end(), greater<SP>());
  cout << (dfs(0, 0, starts[0].second.second, starts[0].second.first) ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (true) {
    cin >> n;
    if (n == 0)
      break;
    solve();
  }
  return 0;
}