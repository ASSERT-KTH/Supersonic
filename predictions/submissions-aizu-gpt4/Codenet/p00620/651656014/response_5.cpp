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
    if (++cur == starts.size()) 
      return true;
    sum = 0;
    x = starts[cur].second.second;
    y = starts[cur].second.first;
  } else if (starts[cur].first < sum) 
    return false;
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
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a = -a;
        used[i][j] = true;
        starts.emplace_back(a, Point(i, j));
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
}

int main() {
  while ((cin >> n) && n) 
    solve();
  return 0;
}