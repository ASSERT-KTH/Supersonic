#include <iostream>
#include <vector>
#include <algorithm>

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
    if (++cur == starts.size()) {
      return true;
    }
    x = starts[cur].second.second;
    y = starts[cur].second.first;
    sum = 0;
  } else if (starts[cur].first < sum) {
    return false;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < n && !used[ny][nx]) {
      used[ny][nx] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny))
        return true;
      used[ny][nx] = false;
    }
  }
  return false;
}

bool solve() {
  starts.clear();
  mat.assign(n, vector<int>(n));
  used.assign(n, vector<bool>(n, false));
  int sum = 0;
  for (auto& row : mat) {
    for (auto& cell : row) {
      cin >> cell;
      sum += cell;
      if (cell < 0) {
        cell *= -1;
        starts.push_back({cell, {starts.size(), starts.size()}});
        used[starts.size() - 1][starts.size() - 1] = true;
      }
    }
  }
  if (sum != 0) {
    return false;
  } else if (starts.size() == 1) {
    return true;
  } else {
    sort(starts.begin(), starts.end(), greater<SP>());
    return dfs(0, 0, starts[0].second.second, starts[0].second.first);
  }
}

int main() {
  while (cin >> n && n != 0) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
  return 0;
}