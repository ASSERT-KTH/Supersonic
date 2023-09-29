#include <iostream>
#include <vector>
#include <array>
using namespace std;

constexpr int MAX_SIZE = 102;
array<array<int, MAX_SIZE>, MAX_SIZE> C;

void meiro(int W, int H, int c) {
  if (W < 0 || W >= MAX_SIZE || H < 0 || H >= MAX_SIZE || C[W][H] != c) {
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
    C.fill({10});
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    while(n--) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;
      auto &v = (d == 0) ? C[x] : C[y];
      fill_n(v.begin() + min(x, y), 4, c);
      fill_n((d == 0 ? C[x+1] : C[y+1]).begin() + min(x, y), 4, c);
    }
    meiro(xs, ys, C[xs][ys]);
    cout << (C[xg][yg] == -1 ? "OK" : "NG") << "\n";
  }
  return 0;
}