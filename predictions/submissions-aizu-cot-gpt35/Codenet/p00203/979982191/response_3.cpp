#include <iostream>
#define N 15
using namespace std;

int solve(int X, int Y, int data[N][N]);

int main() {
  int X, Y;
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    int data[N][N];
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];
    int cnt = solve(X, Y, data);
    cout << cnt << endl;
  }
  return 0;
}

int solve(int X, int Y, int data[N][N]) {
  int memo[N];
  for (int i = 0; i < X; i++)
    memo[i] = -1;

  for (int i = 0; i < X; i++) {
    if (data[0][i] == 0) {
      memo[i] = 1;
    }
  }

  for (int y = 1; y < Y; y++) {
    int prev = memo[0];
    memo[0] = (data[y][0] == 0) ? prev : 0;

    for (int x = 1; x < X; x++) {
      int temp = memo[x];
      if (data[y][x] == 0) {
        memo[x] = memo[x - 1] + prev + memo[x];
      } else {
        memo[x] = 0;
      }
      prev = temp;
    }
  }

  int cnt = 0;
  for (int i = 0; i < X; i++)
    cnt += memo[i];

  return cnt;
}