#include <iostream>
#define N 15
using namespace std;

void func(int, int);
int jump(int, int);

int main() {
  while (1) {
    int X, Y;
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;

    int data[N][N] = {0};
    int memo[N][N] = {0};

    for (int i = 0; i < Y; i++) {
      for (int j = 0; j < X; j++) {
        cin >> data[i][j];
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

    cout << cnt << endl;
  }

  return 0;
}

void func(int y, int x) {
  int Y = 15;
  
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return;
  }

  int left = x - 1;
  int right = x + 1;

  int memo_left = memo[y + 1][left];
  int memo_right = memo[y + 1][right];

  if (0 <= left && data[y + 1][left] == 0) {
    if (memo_left == 0)
      func(y + 1, left);
    memo[y][x] += memo_left;
  }
  if (right < X && data[y + 1][right] == 0) {
    if (memo_right == 0)
      func(y + 1, right);
    memo[y][x] += memo_right;
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
  if (memo[y][x] == 0)
    data[y][x] = 1;
}

int jump(int y, int x) {
  int Y = 15;
  
  while (y < Y - 1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (data[y][x] == 0)
      return y;
    y += 2;
    if (data[y][x] == 1)
      break;
    if (data[y][x] == 0)
      return y;
  }

  return -1;
}