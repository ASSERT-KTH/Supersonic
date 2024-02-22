#include <iostream>
#include <stack>
using namespace std;

int Board[100][100];
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
  stack<pair<int, int>> st;
  st.push({x, y});

  while (!st.empty()) {
    auto [x, y] = st.top();
    st.pop();

    if (Board[x][y] != c) {
      continue;
    } else if (x == xg && y == yg) {
      isOK = true;
      return;
    }

    Board[x][y] = 0;

    if (x + 1 < 100) {
      st.push({x + 1, y});
    }
    if (y + 1 < 100) {
      st.push({x, y + 1});
    }
    if (x - 1 >= 0) {
      st.push({x - 1, y});
    }
    if (y - 1 >= 0) {
      st.push({x, y - 1});
    }
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    isOK = false;
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int j = 0; j < hb; j++) {
        for (int k = 0; k < wb; k++) {
          if (x + k < 100 && y + j < 100) {
            Board[x + k][y + j] = c;
          }
        }
      }
    }
    DFS(Board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}