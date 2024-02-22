#include <iostream>
#include <vector>
using namespace std;

class Maze {
private:
  vector<vector<int>> maze;

public:
  Maze(int rows, int cols, int defaultValue) : maze(rows, vector<int>(cols, defaultValue)) {}

  void meiro(int W, int H, int c) {
    if (maze[W][H] != c) {
      return;
    }
    maze[W][H] = -1;
    meiro(W - 1, H, c);
    meiro(W, H + 1, c);
    meiro(W + 1, H, c);
    meiro(W, H - 1, c);
  }
};

int main() {
  while (1) {
    int w, h;
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0) {
      break;
    }
    Maze maze(w + 2, h + 2, 10);

    int xs, ys, xg, yg;
    scanf("%d %d %d %d", &xs, &ys, &xg, &yg);
    int n;
    scanf("%d", &n);
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &c, &d, &x, &y);
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            maze.meiro(j, k, c);
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            maze.meiro(j, k, c);
          }
        }
      }
    }
    maze.meiro(xs, ys, maze.maze[xs][ys]);
    if (maze.maze[xg][yg] == -1) {
      printf("OK\n");
    } else {
      printf("NG\n");
    }
  }
  return 0;
}