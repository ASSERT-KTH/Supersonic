#include <iostream>
#define N 15
using namespace std;

int main() {
  const int X = N, Y = N;
  int data[Y][X], memo[Y][X];

  while (1) {
    if (X == 0 && Y == 0)
      break;
    
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j], memo[i][j] = 0;

    for (int i = X - 1; i >= 0; i--) {
      for (int j = 0; j < Y; j++) {
        if (j == Y - 1) {
          memo[j][i] = 1;
        } else if (data[j + 1][i] == 0) {
          memo[j][i] += memo[j + 1][i];
        }
        if (i > 0 && data[j + 1][i - 1] == 0) {
          memo[j][i] += memo[j + 1][i - 1];
        }
        if (i < X - 1 && data[j + 1][i + 1] == 0) {
          memo[j][i] += memo[j + 1][i + 1];
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