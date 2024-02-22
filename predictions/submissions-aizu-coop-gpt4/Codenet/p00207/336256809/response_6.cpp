#include <iostream>
#include <stack>
using namespace std;

int C[102][102];

void fill_maze() {
  for (int i = 0; i < 102; i++) {
    for (int j = 0; j < 102; j++) {
      C[i][j] = 10;
    }
  }
}

void meiro_iter(int W, int H, int c) {
  stack<pair<int, int>> s;
  s.push({W, H});

  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    int x = p.first, y = p.second;
    if (x < 0 || y < 0 || x >= 102 || y >= 102 || C[x][y] != c) continue;
  
    C[x][y] = -1;
    s.push({x - 1, y});
    s.push({x, y + 1});
    s.push({x + 1, y});
    s.push({x, y - 1});
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // fast I/O operations
  fill_maze(); // preallocate maze

  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) break;

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;

    int n, c, d, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            C[j][k] = c;
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            C[j][k] = c;
          }
        }
      }
    }
    int start_val = C[xs][ys]; // avoid recomputation
    meiro_iter(xs, ys, start_val);
    if (C[xg][yg] == -1) {
      cout << "OK\n";
    } else {
      cout << "NG\n";
    }
  }
  return 0;
}