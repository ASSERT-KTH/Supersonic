#include <iostream>
#include <vector>
using namespace std;

constexpr int SIZE = 8;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};

void solve(vector<vector<int>>& M, int& y, int& x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j;
      int nx = x + dx[i] * j;
      if (ny >= 0 && ny < SIZE && nx >= 0 && nx < SIZE && M[ny][nx] == 1) {
        solve(M, ny, nx);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int t = 0; t < n; t++) {
    vector<vector<int>> M(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        char c;
        cin >> c;
        M[i][j] = c - '0';
      }
    }
    int x, y;
    cin >> x >> y;
    solve(M, --y, --x);
    cout << "Data " << t + 1 << ":\n";
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        cout << M[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}