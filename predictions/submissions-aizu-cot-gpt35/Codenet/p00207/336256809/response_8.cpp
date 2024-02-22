#include <iostream>
#include <stack>
using namespace std;

bool visited[102][102];

void meiro(int W, int H, int c) {
  stack<pair<int, int>> cells;
  cells.push(make_pair(W, H));

  while (!cells.empty()) {
    pair<int, int> curr = cells.top();
    cells.pop();

    int x = curr.first;
    int y = curr.second;

    if (visited[x][y]) {
      continue;
    }

    visited[x][y] = true;

    if (x > 0 && !visited[x-1][y] && C[x-1][y] == c) {
      cells.push(make_pair(x-1, y));
    }
    if (y < 101 && !visited[x][y+1] && C[x][y+1] == c) {
      cells.push(make_pair(x, y+1));
    }
    if (x < 101 && !visited[x+1][y] && C[x+1][y] == c) {
      cells.push(make_pair(x+1, y));
    }
    if (y > 0 && !visited[x][y-1] && C[x][y-1] == c) {
      cells.push(make_pair(x, y-1));
    }
  }
}

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;

    for (int i = 1; i < 102; i++) {
      for (int j = 1; j < 102; j++) {
        visited[i][j] = false;
      }
    }

    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            visited[j][k] = true;
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            visited[j][k] = true;
          }
        }
      }
    }

    meiro(xs, ys, visited[xs][ys]);

    if (visited[xg][yg]) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }

  return 0;
}