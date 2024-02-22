#include <iostream>
#include <cstring>
#define N 15
using namespace std;

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
    
    for (int i = Y-1; i >= 0; i--) {
      for (int j = 0; j < X; j++) {
        if (data[i][j] == 0) {
          if (i == Y - 1)
            memo[i][j] = 1;
          else {
            if (0 <= j - 1)
              memo[i][j] += memo[i + 1][j - 1];
            if (j + 1 < X)
              memo[i][j] += memo[i + 1][j + 1];
            memo[i][j] += memo[i + 1][j];
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