#include <cstdio>

void func(int, int, int, int, int**, int**);
int jump(int, int, int, int**, int);

int main() {
  int X, Y;

  while (1) {
    scanf("%d %d", &X, &Y);
    if (X == 0 && Y == 0)
      break;

    int** data = new int*[Y];
    int** memo = new int*[Y];
    
    for (int i = 0; i < Y; i++) {
      data[i] = new int[X];
      memo[i] = new int[X];
      for (int j = 0; j < X; j++) {
        data[i][j] = 0;
        memo[i][j] = 0;
      }
    }

    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        scanf("%d", &data[i][j]);

    for (int i = 0; i < X; i++)
      if (data[0][i] == 0)
        func(0, i, X, Y, data, memo);

    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[0][i];

    printf("%d\n", cnt);

    for (int i = 0; i < Y; i++) {
      delete[] data[i];
      delete[] memo[i];
    }
    delete[] data;
    delete[] memo;
  }

  return 0;
}

void func(int y, int x, int X, int Y, int** data, int** memo) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return;
  }

  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    if (memo[y + 1][x - 1] == 0)
      func(y + 1, x - 1, X, Y, data, memo);
    memo[y][x] += memo[y + 1][x - 1];
  }

  if (x + 1 < X && data[y + 1][x + 1] == 0) {
    if (memo[y + 1][x + 1] == 0)
      func(y + 1, x + 1, X, Y, data, memo);
    memo[y][x] += memo[y + 1][x + 1];
  }

  if (data[y + 1][x] == 0) {
    func(y + 1, x, X, Y, data, memo);
    memo[y][x] += memo[y + 1][x];
  }

  if (data[y + 1][x] == 2) {
    int r = jump(y + 1, x, Y, data, X);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      if (memo[r][x] == 0)
        func(r, x, X, Y, data, memo);
      memo[y][x] += memo[r][x];
    }
  }
}

int jump(int y, int x, int Y, int** data, int X) {
  y += 2;
  if (y >= Y - 1)
    return -2;
  if (data[y][x] == 0)
    return y;
  return -1;
}