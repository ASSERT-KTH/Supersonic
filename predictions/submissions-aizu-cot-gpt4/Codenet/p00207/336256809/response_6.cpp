#include <iostream>
using namespace std;

bool visited[102][102];
int C[102][102];

void meiro(int W, int H, int c) {
  if (W < 0 || W >= 102 || H < 0 || H >= 102 || visited[W][H] || C[W][H] != c) {
    return;
  }
  
  visited[W][H] = true;
  C[W][H] = -1;

  meiro(W - 1, H, c);
  meiro(W, H + 1, c);
  meiro(W + 1, H, c);
  meiro(W, H - 1, c);
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    
    for (int i = 0; i < 102; i++) {
      for (int j = 0; j < 102; j++) {
        C[i][j] = 10;
        visited[i][j] = false;
      }
    }
    
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
    
    meiro(xs, ys, C[xs][ys]);
    if (C[xg][yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }
  return 0;
}