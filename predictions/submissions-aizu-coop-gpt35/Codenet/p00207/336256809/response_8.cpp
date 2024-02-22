#include <iostream>
#include <stack>
using namespace std;

void meiro(int W, int H, int c, int* maze) {
  stack<pair<int, int>> positions;
  positions.push({W, H});

  int width = H + 2;
  int targetColor = maze[W * width + H];

  while (!positions.empty()) {
    auto [x, y] = positions.top();
    positions.pop();

    if (x < 0 || x >= W || y < 0 || y >= H) {
      continue;
    }

    if (maze[x * width + y] != targetColor) {
      continue;
    }

    maze[x * width + y] = -1;

    positions.push({x - 1, y});
    positions.push({x, y + 1});
    positions.push({x + 1, y});
    positions.push({x, y - 1});
  }
}

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int* maze = new int[(w + 2) * (h + 2)]();

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            maze[j * (h + 2) + k] = c;
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            maze[j * (h + 2) + k] = c;
          }
        }
      }
    }

    meiro(xs, ys, maze[xs * (h + 2) + ys], maze);

    if (maze[xg * (h + 2) + yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }

    delete[] maze;
  }

  return 0;
}