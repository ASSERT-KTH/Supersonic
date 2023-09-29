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
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < X; j++) {
        data[i][j] = 0;
      }
    }
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
  if (0 <= x - 1 && data[y + 1][x - 1] == 0) {
    if (memo[y + 1][x - 1] == 0)
      func(y + 1, x - 1);
    memo[y][x] += memo[y + 1][x - 1];
  }
  if (x + 1 < X && data[y + 1][x + 1] == 0) {
    if (memo[y + 1][x + 1] == 0