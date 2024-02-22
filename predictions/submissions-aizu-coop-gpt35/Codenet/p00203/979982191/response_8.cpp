#include <iostream>
#include <cstring>
#define N 15
using namespace std;

void func(int row, int x, int prevRow);
int jump(int y, int x);

int X, Y, data[N][N], memo[N];

int main() {
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    
    memset(data, 0, sizeof(data));
    
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j], memo[j] = 0;
    
    for (int i = 0; i < X; i++)
      if (data[0][i] == 0)
        func(1, i, 0);
    
    int cnt = 0;
    for (int i = 0; i < X; i++)
      cnt += memo[i];
    
    cout << cnt << endl;
  }
  
  return 0;
}

void func(int row, int x, int prevRow) {
  if (row == Y) {
    memo[x] = 1;
    return;
  }
  
  if (0 <= x - 1 && data[row][x - 1] == 0) {
    memo[x] += memo[x - 1];
    func(row + 1, x - 1, row);
  }
  
  if (x + 1 < X && data[row][x + 1] == 0) {
    memo[x] += memo[x + 1];
    func(row + 1, x + 1, row);
  }
  
  if (data[row][x] == 0) {
    memo[x] += memo[x];
    func(row + 1, x, row);
  }
  
  if (data[row][x] == 2) {
    int r = jump(row, x);
    if (r == -2)
      memo[x] += 1;
    else if (r != -1) {
      if (memo[x] == 0)
        func(r, x, row);
      memo[x] += memo[x];
    }
  }
  
  if (memo[x] == 0)
    data[prevRow][x] = 1;
}

int jump(int y, int x) {
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