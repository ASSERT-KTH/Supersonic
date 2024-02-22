#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

void solve(Matrix& M, int y, int x) {
  M[y][x] = 0;
  vector<pair<int, int>> stack;
  stack.emplace_back(y, x);

  while (!stack.empty()) {
    int curY, curX;
    tie(curY, curX) = stack.back();
    stack.pop_back();

    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = curY + (i == 0 ? j : (i == 2 ? -j : 0));
        int nx = curX + (i == 1 ? j : (i == 3 ? -j : 0));

        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
          M[ny][nx] = 0;
          stack.emplace_back(ny, nx);
        }
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    Matrix M(8, vector<int>(8));

    for (int j = 0; j < 8; j++) {
      string s;
      cin >> s;

      for (int k = 0; k < 8; k++) {
        M[j][k] = s[k] - '0';
      }
    }

    int x, y;
    cin >> x >> y;
    x--;
    y--;

    if (x >= 0 && x < 8 && y >= 0 && y < 8 && M[y][x] == 1) {
      solve(M, y, x);
    }

    cout << "Data " << i + 1 << ":" << endl;
    for (const auto& row : M) {
      for (int val : row) {
        cout << val;
      }
      cout << endl;
    }
  }

  return 0;
}