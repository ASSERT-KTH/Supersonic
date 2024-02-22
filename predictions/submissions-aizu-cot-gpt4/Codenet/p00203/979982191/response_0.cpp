#include <iostream>
#include <vector>
using namespace std;
void func(int, int);
int jump(int, int);
int X, Y;
vector<vector<int>> data, memo;

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    data = vector<vector<int>>(Y, vector<int>(X));
    memo = vector<vector<int>>(Y, vector<int>(X));
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];
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
    memo[y][x] = 1;
    return;
  }
  for (int dx = -1; dx <= 1; dx++) {
    int nx = x + dx;
    if (nx >= 0 && nx < X && data[y + 1][nx] == 0) {
      if (memo[y + 1][nx] == 0)
        func(y + 1, nx);
      memo[y][x] += memo[y + 1][nx];
    }
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
  while (1) {
    y += 2;
    if (y >= Y - 1 || data[y][x] == 1)
      break;
    if (data[y][x] == 0)
      return y;
  }
  return -1;
}