#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> Point;
typedef pair<int, Point> SP;
typedef vector<vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int n;
Mat mat;
vector<bool> used;
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
    int index = ny * n + nx;
    
    if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[index]) {
      used[index] = true;
      if (dfs(cur, sum + mat[ny][nx], nx, ny))
        return true;
      used[index] = false;
    }
  }
  
  return false;
}

void solve() {
  mat = Mat(n, vector<int>(n));
  used = vector<bool>(n * n, false);
  starts.resize(0);
  int sum = 0;
  
  rep(i, n) {
    rep(j, n) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        int index = i * n + j;
        used[index] = true;
        starts.push_back(SP(a, Point(i, j)));
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
    priority_queue<SP> pq(starts.begin(), starts.end());
    ret = dfs(0, 0, pq.top().second.second, pq.top().second.first);
  }
  
  printf("%s\n", ret ? "YES" : "NO");
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