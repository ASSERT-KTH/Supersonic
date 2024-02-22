#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Mat;
typedef pair<int, int> Point;
typedef pair<int, Point> SP;

const int NUM_DIRECTIONS = 4;

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
  for (int i = 0; i < NUM_DIRECTIONS; i++) {
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
  
  if (sum != 0) {
    cout << "NO\n";
    return;
  }
  
  if (starts.size() == 1) {
    cout << "YES\n";
    return;
  }
  
  if (dfs(0, 0, starts[0].second.second, starts[0].second.first)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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