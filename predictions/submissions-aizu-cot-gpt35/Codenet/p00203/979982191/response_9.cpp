#include <iostream>
#include <cstring>
#define N 15
using namespace std;

void func(int, int, int, int*);
int jump(int, int, int, int*);

int main() {
  int X, Y;
  do {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    int data[N] = {0};
    int memo[N] = {0};
    for (int i = 0; i < Y; i++) {
      for (int j = 0; j < X; j++) {
        cin >> data[j];
        memo[j] = 0;
      }
      func(0, i, X, memo);
    }
    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[i];
    cout << cnt << endl;
  } while (true);
  return 0;
}

void func(int y, int x, int X, int* memo) {
  if (y == X - 1) {
    memo[X - 1] = 1;
    return;
  }
  if (0 <= x - 1 && x + 1 < X && data[y + 1][x - 1] == 0 && data[y + 1][x + 1] == 0) {
    if (memo[y + 1][x - 1] == 0)
      func(y + 1, x - 1, X, memo);
    memo[y][x] += memo[y + 1][x - 1];
  }
  if (data[y + 1][x] == 0) {
    if (memo[y + 1][x] == 0)
      func(y + 1, x, X, memo);
    memo[y][x] += memo[y + 1][x];
  }
  if (0 <= x - 1 && x + 1 < X && data[y + 1][x - 1] == 0 && data[y + 1][x + 1] == 0 && data[y + 1][x] == 2) {
    int r = jump(y + 1, x, X, memo);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      if (memo[r][x] == 0)
        func(r, x, X, memo);
      memo[y][x] += memo[r][x];
    }
  }
  if (memo[y][x] == 0)
    data[y][x] = 1;
}

int jump(int y, int x, int X, int* memo) {
  while (true) {
    y += 2;
    if (data[y][x] != 0)
      break;
    if (y >= X - 2)
      return -2;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}