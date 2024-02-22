#include <iostream>
#define N 15
using namespace std;

void func(int, int);
int jump(int, int);

int X, Y, data[N][N], memo[N][N];
int jump_table[N][N];

int main() {
  // Initialize jump table
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      jump_table[i][j] = -1;
    }
  }
  jump_table[1][0] = 3;
  jump_table[1][1] = 4;
  jump_table[1][2] = 5;

  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    
    // Initialize data and memo arrays
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

  if (memo[y][x] == 0)
    data[y][x] = 1;
}

int jump(int y, int x) {
  if (jump_table[y][x] != -1)
    return jump_table[y][x];
  
  while (1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (y >= Y - 1)
      return -2;
    if (data[y][x] == 0)
      return jump_table[y][x] = y;
  }

  return jump_table[y][x] = -1;
}