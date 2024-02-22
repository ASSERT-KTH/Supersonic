#include <iostream>
#include <cstring>
#define N 15
using namespace std;

void func(int, int);

int X, Y, data[N][N], memo[N][N];

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    
    memset(data, 0, sizeof(data));
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];

    for (int i = 0; i < X; i++)
      if (data[0][i] == 0 && memo[0][i] == 0)
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

  for (int dx = -1; dx <= 1; dx++) {
    int nx = x + dx;
    if (0 <= nx && nx < X && data[y + 1][nx] == 0) {
      if (memo[y + 1][nx] == 0) func(y + 1, nx);
      memo[y][x] += memo[y + 1][nx];
    }
  }

  if (data[y + 1][x] == 2) {
    int r = y + 2;
    while (r < Y && data[r][x] != 1) {
      if (data[r][x] == 0) {
        if (memo[r][x] == 0) func(r, x);
        memo[y][x] += memo[r][x];
        break;
      }
      r += 2;
    }
    if (r >= Y) memo[y][x]++;
  }

  if (memo[y][x] == 0) data[y][x] = 1;
}