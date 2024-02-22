#include <iostream>

const int N = 15;

void func(int, int);
int jump(int, int);

int main() {
  int X, Y;
  while (true) {
    std::cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;

    int data[N][N] = {};
    int memo[N][N] = {};

    for (int i = 0; i < Y; i++) {
      for (int j = 0; j < X; j++) {
        std::cin >> data[i][j];
        memo[i][j] = 0;
      }
    }

    for (int i = 0; i < X; i++) {
      if (data[0][i] == 0)
        func(0, i);
    }

    int cnt = 0;
    for (int i = 0; i < X; i++) {
      cnt += memo[0][i];
    }

    std::cout << cnt << std::endl;
  }

  return 0;
}

void func(int y, int x) {
  const int Y = N;
  const int X = N;

  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return;
  }

  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    if (memo[y + 1][x - 1] == 0)
      func(y + 1, x - 1);
    memo[y][x] += memo[y + 1][x - 1];
  }

  if (x + 1 < X && data[y + 1][x + 1] == 0) {
    if (memo[y + 1][x + 1] == 0)
      func(y + 1, x + 1);
    memo[y][x] += memo[y + 1][x + 1];
  }

  if (data[y + 1][x] == 0) {
    if (memo[y + 1][x] == 0)
      func(y + 1, x);
    memo[y][x] += memo[y + 1][x];
  }

  if (data[y + 1][x] == 2) {
    int r = jump(y + 1, x);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      if (memo[r][x] == 0)
        func(r, x);
      memo[y][x] += memo[r][x];
    }
  }

  data[y][x] = 1;
}

int jump(int y, int x) {
  const int Y = N;

  while (true) {
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