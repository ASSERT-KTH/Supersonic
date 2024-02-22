#include <iostream>
using namespace std;

void meiro(int W, int H, int** C, int c) {
  if (C[W][H] != c) {
    return;
  }
  C[W][H] = -1;

  // Explore left neighbor
  if (W > 0 && C[W - 1][H] == c) {
    meiro(W - 1, H, C, c);
  }

  // Explore right neighbor
  if (W < 101 && C[W + 1][H] == c) {
    meiro(W + 1, H, C, c);
  }

  // Explore top neighbor
  if (H > 0 && C[W][H - 1] == c) {
    meiro(W, H - 1, C, c);
  }

  // Explore bottom neighbor
  if (H < 101 && C[W][H + 1] == c) {
    meiro(W, H + 1, C, c);
  }
}

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    // Allocate memory for the maze array dynamically
    int** C = new int*[w];
    for (int i = 0; i < w; i++) {
      C[i] = new int[h];
    }

    // No need to initialize the C array

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

    meiro(xs, ys, C, C[xs][ys]);
    if (C[xg][yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }

    // Free memory allocated for the maze array
    for (int i = 0; i < w; i++) {
      delete[] C[i];
    }
    delete[] C;
  }

  return 0;
}