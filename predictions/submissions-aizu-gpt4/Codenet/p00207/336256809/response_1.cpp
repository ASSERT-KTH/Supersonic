#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> C(102, vector<int>(102));
void meiro(int W, int H, int c) {
  if (C[W][H] != c || W < 0 || H < 0 || W >= 102 || H >= 102) {
    return;
  }
  C[W][H] = -1;
  meiro(W - 1, H, c);
  meiro(W, H + 1, c);
  meiro(W + 1, H, c);
  meiro(W, H - 1, c);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    for (int i = 0; i < 102; i++) {
      fill(C[i].begin(), C[i].end(), 10);
    }
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      for (int j = x; j < x + (d == 0 ? 4 : 2); j++) {
        for (int k = y; k < y + (d == 0 ? 2 : 4); k++) {
          C[j][k] = c;
        }
      }
    }
    meiro(xs, ys, C[xs][ys]);
    cout << (C[xg][yg] == -1 ? "OK" : "NG") << endl;
  }
  return 0;
}