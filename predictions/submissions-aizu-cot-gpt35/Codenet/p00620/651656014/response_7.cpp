#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n;
Mat mat;
vector<pair<int, pair<int, int>>> starts;

bool dfs(int cur, int sum, int x, int y) {
  if (starts[cur].first == sum) {
    cur++;
    sum = 0;
    if (cur >= starts.size()) {
      return true;
    }
    x = starts[cur].second.second;
    y = starts[cur].second.first;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < n && mat[ny][nx] > 0) {
      mat[ny][nx] *= -1;
      if (dfs(cur, sum + mat[ny][nx], nx, ny))
        return true;
      mat[ny][nx] *= -1;
    }
  }
  return false;
}

void solve() {
  mat = Mat(n, vector<int>(n));
  starts.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      if (a < 0) {
        a *= -1;
        mat[i][j] = -a;
        starts.push_back(make_pair(a, make_pair(i, j)));
      } else {
        mat[i][j] = a;
      }
    }
  }
  sort(starts.begin(), starts.end(), greater<pair<int, pair<int, int>>>());
  bool ret = dfs(0, 0, starts[0].second.second, starts[0].second.first);
  cout << (ret ? "YES" : "NO") << endl;
}

int main() {
  do {
    cin >> n;
    if (n == 0)
      break;
    solve();
  } while (true);
  
  return 0;
}