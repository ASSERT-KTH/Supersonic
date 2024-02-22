#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
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
priority_queue<SP, vector<SP>, less<SP>> starts;

bool is_valid(int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < n && !used[y][x];
}

void solve() {
  while (!starts.empty()) starts.pop();
  int sum = 0;
  rep(i, n) {
    rep(j, n) {
      int a;
      scanf("%d", &a);
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
  if (sum != 0) {
    ret = false;
  } else if (starts.size() == 1) {
    ret = true;
  } else {
    SP start = starts.top();
    starts.pop();
    stack<SP> dfs_stack;
    dfs_stack.push(start);
    while (!dfs_stack.empty()) {
      SP cur = dfs_stack.top();
      dfs_stack.pop();
      if (cur.first == 0) {
        if (starts.empty()) {
          ret = true;
          break;
        }
        cur = starts.top();
        starts.pop();
      }
      rep(i, 4) {
        int nx = cur.second.second + dx[i];
        int ny = cur.second.first + dy[i];
        if (is_valid(nx, ny)) {
          used[ny][nx] = true;
          dfs_stack.push(SP(cur.first - mat[ny][nx], Point(ny, nx)));
        }
      }
    }
  }
  printf("%s\n", ret ? "YES" : "NO");
  return;
}

int main() {
  mat = Mat(100, vector<int>(100));
  used = vector<vector<bool>>(100, vector<bool>(100, false));
  while (true) {
    scanf("%d", &n);
    if (n == 0)
      break;
    rep(i, n) rep(j, n) used[i][j] = false;
    solve();
  }
  return 0;
}