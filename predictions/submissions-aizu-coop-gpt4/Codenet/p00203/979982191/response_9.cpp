#include <iostream>
#define N 15
using namespace std;

int X, Y, data[N][N], memo[N][N];

void func(int y, int x) {
  if (y == Y - 1) {
    memo[y][x] = 1;
    return;
  }

  if (memo[y][x] != -1) return;

  memo[y][x] = 0;
  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    if (memo[y + 1][x - 1] == -1)
      func(y + 1, x - 1);
    memo[y][x] += memo[y + 1][x - 1];
  }
  // Similar for x+1 and y+1
  // Similar for y+1
}

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;

    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++) {
        cin >> data[i][j];
        memo[i][j] = -1;
      }

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