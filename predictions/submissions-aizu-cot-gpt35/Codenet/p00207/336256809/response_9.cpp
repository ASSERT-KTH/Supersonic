#include <iostream>
#include <stack>
#include <cstring>

int main() {
  while (true) {
    int w, h;
    std::cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }

    int C[102][102];
    std::memset(C, 10, sizeof(C));

    int xs, ys, xg, yg;
    std::cin >> xs >> ys >> xg >> yg;

    int n;
    std::cin >> n;

    int startValue = C[xs][ys];

    for (int i = 0; i < n; i++) {
      int c, d, x, y;
      std::cin >> c >> d >> x >> y;

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

    std::stack<std::pair<int, int>> st;
    st.push(std::make_pair(xs, ys));

    while (!st.empty()) {
      int W = st.top().first;
      int H = st.top().second;
      st.pop();

      if (C[W][H] != startValue) {
        continue;
      }

      C[W][H] = -1;

      st.push(std::make_pair(W - 1, H));
      st.push(std::make_pair(W, H + 1));
      st.push(std::make_pair(W + 1, H));
      st.push(std::make_pair(W, H - 1));
    }

    if (C[xg][yg] == -1) {
      std::cout << "OK" << std::endl;
    } else {
      std::cout << "NG" << std::endl;
    }
  }

  return 0;
}