#include <iostream>
#include <cstring>
#define N 15
using namespace std;

int X, Y, data[N][N], memo[N][N];
int cnt;

void func(int y, int x) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    cnt++;
    return;
  }
  if (memo[y][x] != -1) {
    cnt += memo[y][x];
    return;
  }
  memo[y][x] = 0;
  if (0 <= x - 1 && data[y + 1][x - 1] == 0)
    func(y + 1, x - 1);
  if (x + 1 < X && data[y + 1][x + 1] == 0)
    func(y + 1, x + 1);
  if (data[y + 1][x] == 0)
    func(y + 1, x);
  if (data[y + 1][x] == 2) {
    int r = y + 2;
    while (r < Y && data[r][x] != 1) {
      if (data[r][x] == 0)
        func(r, x);
      r += 2;
    }
    if (r == Y)
      memo[y][x] = 1;
    else
      memo[y][x] = memo[r][x];
  }
  cnt += memo[y][x];
}

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    memset(memo, -1, sizeof memo);
    cnt = 0;
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];
    for (int i = 0; i < X; i++)
      if (data[0][i] == 0)
        func(0, i);
    cout << cnt << endl;
  }
  return 0;
}