#include <iostream>
#include <vector>
using namespace std;

int y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
        if (M[ny][nx] == 1)
          solve(ny, nx);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        char c;
        cin >> c;
        M[j][k] = c - '0';
      }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) {
        cout << M[j][k];
      }
      cout << endl;
    }
  }
  return 0;
}