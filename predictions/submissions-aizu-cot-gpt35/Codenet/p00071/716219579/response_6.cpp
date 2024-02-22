#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve(vector<vector<int>>& M, int y, int x) {
  M[y][x] = 0;
  queue<pair<int, int>> q;
  q.push({y, x});

  while (!q.empty()) {
    int sy = q.front().first;
    int sx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = sy + dy[i] * j;
        int nx = sx + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
          M[ny][nx] = 0;
          q.push({ny, nx});
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
      for (int k = 0; k < 8; k++) {
        cin >> M[j][k];
      }
    }

    int x, y;
    cin >> x >> y;
    solve(M, y - 1, x - 1);

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