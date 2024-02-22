#include <iostream>
#include <stack>
using namespace std;

const int MAX_SIZE = 102;
int C[MAX_SIZE * MAX_SIZE];

void meiro(int W, int H, int c) {
  stack<pair<int, int>> st;
  st.push({W, H});

  while (!st.empty()) {
    auto [w, h] = st.top();
    st.pop();

    if (C[w * MAX_SIZE + h] != c) {
      continue;
    }

    C[w * MAX_SIZE + h] = -1;

    if (w > 0) st.push({w - 1, h});
    if (h < MAX_SIZE - 1) st.push({w, h + 1});
    if (w < MAX_SIZE - 1) st.push({w + 1, h});
    if (h > 0) st.push({w, h - 1});
  }
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;

    if (w == 0 && h == 0) {
      break;
    }

    int n;
    cin >> n;

    for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
      C[i] = 10;
    }

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;

    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            C[j * MAX_SIZE + k] = c;
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            C[j * MAX_SIZE + k] = c;
          }
        }
      }
    }

    meiro(xs, ys, C[xs * MAX_SIZE + ys]);

    if (C[xg * MAX_SIZE + yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }

  return 0;
}