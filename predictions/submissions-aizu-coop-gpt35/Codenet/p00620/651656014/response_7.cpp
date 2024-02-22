#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> Point;
typedef pair<int, Point> SP;
typedef vector<int> Mat;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
Mat mat;
vector<int> used;
vector<SP> starts(0);
bool dfs(int cur, int sum, int x, int y) {
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
      if (0 <= nx && nx < n && 0 <= ny && ny < n && used[ny*n+nx] == 0) {
        used[ny*n+nx] = 1;
        found = true;
        x = nx;
        y = ny;
        sum += mat[ny*n+nx];
        break;
      }
    }
    if (!found) {
      if (cur == 0) {
        return false;
      } else {
        used[y*n+x] = 0;
        cur--;
        sum -= mat[y*n+x];
        x = starts[cur].second.second;
        y = starts[cur].second.first;
      }
    }
  }
}
void solve() {
  mat = Mat(n*n);
  used = vector<int>(n*n, 0);
  starts.clear();
  int sum = 0;
  rep(i, n) {
    rep(j, n) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        used[i*n+j] = 1;
        starts.push_back(SP(a, Point(i, j)));
      }
      mat[i*n+j] = a;
    }
  }
  bool ret = false;
  if (sum != 0) {
    ret = false;
  } else if (starts.size() == 1) {
    ret = true;
  } else {
    sort(starts.begin(), starts.end(), greater<SP>());
    ret = dfs(0, 0, starts[0].second.second, starts[0].second.first);
  }
  cout << (ret ? "YES" : "NO") << endl;
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