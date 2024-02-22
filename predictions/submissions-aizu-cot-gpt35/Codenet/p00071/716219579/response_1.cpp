#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve(vector<vector<int>>& M, int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
        if (M[ny][nx] == 1) {
          solve(M, ny, nx);
        }
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> M(8, vector<int>(8));
    for (int j = 0; j < 8; j++) {
      string s;
      cin >> s;
      for (int k = 0; k < 8; k++) {
        M[j][k] = s[k] - '0';
      }
    }
    int x, y;
    cin >> x >> y;
    solve(M, y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    for (const auto& row : M) {
      for (int cell : row) {
        cout << cell;
      }
      cout << endl;
    }
  }
}