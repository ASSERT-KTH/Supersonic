#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
#define REP(i, N) for (int i = 0; i < (N); i++)

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> M(8, vector<int>(8));

void solve(int y, int x) {
  stack<pair<int, int>> s;
  s.push({y, x});
  while (!s.empty()) {
    int cy = s.top().first, cx = s.top().second;
    s.pop();
    M[cy][cx] = 0;
    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i], nx = cx + dx[i];
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1)
        s.push({ny, nx});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, x, y;
  string s;
  cin >> n;
  REP(i, n) {
    REP(j, 8) {
      cin >> s;
      REP(k, 8) { M[j][k] = s[k] - '0'; }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":\n";
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << "\n";
    }
  }
  return 0;
}