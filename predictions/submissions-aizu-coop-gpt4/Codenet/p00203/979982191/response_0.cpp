#include <iostream>
#define N 15
using namespace std;
void func(int, int);
int jump(int, int);
int X, Y, data[N][N], memo[N][N];
int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j], memo[i][j] = 0;
    for (int i = 0; i < X; i++)
      if (data[0][i] == 0)
        func(0, i);
    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[0][i];
    cout << cnt << endl;
  }
  return 0;
}
void func(int y, int x) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return;
  }
  int next_y = y + 1;
  if (0 <= x - 1 && data[next_y][x - 1] == 0) {
    if (memo[next_y][x - 1] == 0)
      func(next_y, x - 1);
    memo[y][x] += memo[next_y][x - 1];
  }
  if (x + 1 < X && data[next_y][x + 1] == 0) {
    if (memo[next_y][x + 1] == 0)
      func(next_y, x + 1);
    memo[y][x] += memo[next_y][x + 1];
  }
  if (data[next_y][x] == 0) {
    if (memo[next_y][x] == 0)
      func(next_y, x);
    memo[y][x] += memo[next_y][x];
  }
  if (data[next_y][x] == 2) {
    int r = jump(next_y, x);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      if (memo[r][x] == 0)
        func(r, x);
      memo[y][x] += memo[r][x];
    }
  }
  if (memo[y][x] == 0)
    data[y][x] = 1;
}
int jump(int y, int x) {
  while (1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (y >= Y - 1)
      return -2;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}