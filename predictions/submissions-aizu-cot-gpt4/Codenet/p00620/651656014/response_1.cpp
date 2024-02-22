#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int n;
int mat[100][100];
bool used[100][100];
pair<int, pair<int, int>> starts[100];
bool dfs(int cur, int sum, int x, int y) {
  if (starts[cur].first == sum) {
    cur++;
    sum = 0;
    if (cur >= n) {
      return true;
    }
    x = starts[cur].second.second;
    y = starts[cur].second.first;
  } else if (starts[cur].first < sum) {
    return false;
  }
  int *pdx = dx, *pdy = dy;
  for (int i = 0; i < 4; i++) {
    int nx = x + *pdx++;
    int ny = y + *pdy++;
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
  memset(mat, 0, sizeof(mat));
  memset(used, false, sizeof(used));
  memset(starts, 0, sizeof(starts));
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      scanf("%d", &a);
      sum += a;
      if (a < 0) {
        a = -a;
        used[i][j] = true;
        starts[i].first = a;
        starts[i].second.first = i;
        starts[i].second.second = j;
      }
      mat[i][j] = a;
    }
  }
  bool ret = false;
  if (sum != 0) {
    ret = false;
  } else if (n == 1) {
    ret = true;
  } else {
    sort(starts, starts + n, greater<pair<int, pair<int, int>>>());
    ret = dfs(0, 0, starts[0].second.second, starts[0].second.first);
  }
  cout << (ret ? "YES\n" : "NO\n");
  return;
}
int main() {
  while (true) {
    scanf("%d", &n);
    if (n == 0)
      break;
    solve();
  }
  return 0;
}