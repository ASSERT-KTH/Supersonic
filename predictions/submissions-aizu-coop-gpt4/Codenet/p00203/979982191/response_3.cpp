#include <iostream>
#define N 15
using namespace std;
int jump(int, int);
int X, Y, data[N][N], memo[N][N];
int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        data[i][j] = 0;
      }
    }
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j], memo[i][j] = 0;
    for (int y = Y - 1; y >= 0; y--) {
      for (int x = 0; x < X; x++) {
        if (data[y][x] == 0) {
          if (y == Y - 1)
            memo[y][x] = 1;
          else {
            if (0 <= x - 1 && data[y + 1][x - 1] == 0)
              memo[y][x] += memo[y + 1][x - 1];
            if (x + 1 < X && data[y + 1][x + 1] == 0)
              memo[y][x] += memo[y + 1][x + 1];
            if (data[y + 1][x] == 0)
              memo[y][x] += memo[y + 1][x];
            if (data[y + 1][x] == 2) {
              int r = jump(y + 1, x);
              if (r == -2)
                memo[y][x] += 1;
              else if (r != -1)
                memo[y][x] += memo[r][x];
            }
          }
        }
      }
    }
    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[0][i];
    cout << cnt << endl;
  }
  return 0;
}
int jump(int y, int x) {
  for (; y < Y; y += 2) {
    if (data[y][x] == 1)
      break;
    if (y >= Y - 1)
      return -2;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}