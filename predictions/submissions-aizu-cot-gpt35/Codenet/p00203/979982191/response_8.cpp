#include <iostream>
#define N 15
using namespace std;

void func(int, int);
int jump(int, int);

int X, Y, data[N][N], memo[N][N], cache[N][N];

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        data[i][j] = 0;
        memo[i][j] = 0;
        cache[i][j] = -1;
      }
    }

    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];

    int cnt = 0;
    for (int i = 0; i < X; i++) {
      if (data[0][i] == 0) {
        if (cache[0][i] == -1)
          func(0, i);
        cnt += cache[0][i];
      }
    }

    cout << cnt << endl;
  }

  return 0;
}

void func(int y, int x) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    cache[Y - 1][x] = 1;
    return;
  }

  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    if (cache[y + 1][x - 1] == -1)
      func(y + 1, x - 1);
    memo[y][x] += cache[y + 1][x - 1];
  }
  if (x + 1 < X && data[y + 1][x + 1] == 0) {
    if (cache[y + 1][x + 1] == -1)
      func(y + 1, x + 1);
    memo[y][x] += cache[y + 1][x + 1];
  }
  if (data[y + 1][x] == 0) {
    if (cache[y + 1][x] == -1)
      func(y + 1, x);
    memo[y][x] += cache[y + 1][x];
  }
  if (data[y + 1][x] == 2) {
    int r = jump(y + 1, x);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      if (cache[r][x] == -1)
        func(r, x);
      memo[y][x] += cache[r][x];
    }
  }

  cache[y][x] = memo[y][x];
}

int jump(int y, int x) {
  while (1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (y + 2 >= Y)
      return -2;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}