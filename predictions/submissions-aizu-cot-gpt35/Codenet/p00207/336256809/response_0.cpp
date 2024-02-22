#include <iostream>
#include <stack>
using namespace std;

int main() {
  while (true) {
    int w, h;
    cin >> w >> h;

    if (w == 0 && h == 0) {
      break;
    }

    int C[w + 2][h + 2];

    for (int i = 0; i < w + 2; i++) {
      for (int j = 0; j < h + 2; j++) {
        if (i == 0 || i == w + 1 || j == 0 || j == h + 1) {
          C[i][j] = 10;
        }
      }
    }

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int c, d, x, y;
      cin >> c >> d >> x >> y;

      for (int j = x; j < x + 2; j++) {
        for (int k = y; k < y + 2; k++) {
          C[j][k] = c;
        }
      }
    }

    stack<pair<int, int>> st;
    st.push({xs, ys});

    while (!st.empty()) {
      int W = st.top().first;
      int H = st.top().second;
      st.pop();

      if (C[W][H] != C[xs][ys]) {
        continue;
      }

      C[W][H] = -1;

      st.push({W - 1, H});
      st.push({W, H + 1});
      st.push({W + 1, H});
      st.push({W, H - 1});
    }

    cout << (C[xg][yg] == -1 ? "OK" : "NG") << endl;
  }

  return 0;
}