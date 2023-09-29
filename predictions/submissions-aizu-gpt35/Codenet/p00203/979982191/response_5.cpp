#include <iostream>
#include <cstring>
#define N 15
using namespace std;
int X, Y, data[N][N], memo[N][N];
int func(int y, int x) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return 1;
  }
  int& ans = memo[y][x];
  if (ans != -1) {
    return ans;
  }
  ans = 0;
  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    ans += func(y + 1, x - 1);
  }
  if (x + 1 < X && data[y + 1][x + 1] == 0) {
    ans += func(y + 1, x + 1);
  }
  if (data[y + 1][x] == 0) {
    ans += func(y + 1, x);
  }
  if (data[y + 1][x] == 2) {
    int r = y + 1;
    while (r < Y - 1 && data[r + 1][x] != 1) {
      r++;
      if (data[r][x] == 0) {
        ans += func(r, x);
        break;
      }
    }
    if (r == Y - 1) {
      ans += 1;
    }
  }
  return ans;
}
int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    for (int i = 0; i < Y; i++) {
      for (int j = 0; j < X; j++) {
        cin >> data[i][j];
      }
    }
    memset(memo, -1, sizeof(memo));
    int cnt = 0;
    for (int i = 0; i < X; i++) {
      if (data[0][i] == 0) {
        cnt += func(0, i);
      }
    }
    cout << cnt << endl;
  }
  return 0;
}