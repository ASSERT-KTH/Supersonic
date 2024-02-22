#include <iostream>
#include <array>
#include <string>
#include <stack>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

array<array<ll, 8>, 8> M;
array<int, 4> dx = {1, 0, -1, 0};
array<int, 4> dy = {0, 1, 0, -1};

void solve(int y, int x) {
  // Use a stack to avoid recursion
  stack<P> stk;
  stk.push({y, x});

  while (!stk.empty()) {
    P p = stk.top();
    stk.pop();

    M[p.first][p.second] = 0;

    for (int i = 0; i < 4; i++) {
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
        stk.push({ny, nx});
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (auto &row : M) {
      string s;
      cin >> s;
      for (int k = 0; k < 8; k++) {
        row[k] = s[k] - '0';
      }
    }

    int x, y;
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;

    for (const auto &row : M) {
      for (const auto &cell : row) {
        cout << cell;
      }
      cout << endl;
    }
  }
}