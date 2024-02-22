#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef vector<vector<int>> Mat;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool solve() {
  int n;
  cin >> n;
  if (n == 0)
    return false;

  Mat mat(n, vector<int>(n));
  vector<vector<bool>> used(n, vector<bool>(n, false));
  priority_queue<pair<int, pair<int, int>>> starts;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      sum += a;
      if (a < 0) {
        a *= -1;
        used[i][j] = true;
        starts.push(make_pair(a, make_pair(i, j)));
      }
      mat[i][j] = a;
    }
  }

  bool ret = false;
  if (sum == 0 && starts.size() > 1) {
    while (!starts.empty()) {
      int cur = starts.top().first;
      int x = starts.top().second.second;
      int y = starts.top().second.first;
      starts.pop();

      if (cur == 0) {
        ret = true;
        break;
      }

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !used[ny][nx]) {
          used[ny][nx] = true;
          starts.push(make_pair(cur - mat[ny][nx], make_pair(ny, nx)));
        }
      }
    }
  }

  cout << (ret ? "YES" : "NO") << endl;
  return true;
}

int main() {
  while (true) {
    if (!solve())
      break;
  }
  return 0;
}