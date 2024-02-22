#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(int y, int x, const int X, const int Y, vector<vector<int>> &data, vector<vector<int>> &memo);
int jump(int y, int x, const int Y, vector<vector<int>> &data);

int main() {
  while (1) {
    int X, Y;
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;

    vector<vector<int>> data(Y, vector<int>(X));
    vector<vector<int>> memo(Y, vector<int>(X));

    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];

    for (int i = 0; i < X; i++)
      if (data[0][i] == 0)
        func(0, i, X, Y, data, memo);

    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[0][i];

    cout << cnt << endl;
  }
  return 0;
}

void func(int y, int x, const int X, const int Y, vector<vector<int>> &data, vector<vector<int>> &memo) {
  if (y == Y - 1) {
    memo[Y - 1][x] = 1;
    return;
  }
  
  int y_plus_1 = y+1;
  
  if (0 <= x - 1 && data[y_plus_1][x - 1] == 0) {
    func(y_plus_1, x - 1, X, Y, data, memo);
    memo[y][x] += memo[y_plus_1][x - 1];
  }
  if (x + 1 < X && data[y_plus_1][x + 1] == 0) {
    func(y_plus_1, x + 1, X, Y, data, memo);
    memo[y][x] += memo[y_plus_1][x + 1];
  }
  if (data[y_plus_1][x] == 0) {
    func(y_plus_1, x, X, Y, data, memo);
    memo[y][x] += memo[y_plus_1][x];
  }
  if (data[y_plus_1][x] == 2) {
    int r = jump(y_plus_1, x, Y, data);
    if (r == -2)
      memo[y][x] += 1;
    else if (r != -1) {
      func(r, x, X, Y, data, memo);
      memo[y][x] += memo[r][x];
    }
  }
  if (memo[y][x] == 0)
    data[y][x] = 1;
}

int jump(int y, int x, const int Y, vector<vector<int>> &data) {
  while (1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (y >= Y - 1)
      return -2;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}