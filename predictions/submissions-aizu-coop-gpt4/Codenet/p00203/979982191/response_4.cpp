#include <iostream>
#include <cstring>
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
    
    memset(data, 0, sizeof(data));
    memset(memo, 0, sizeof(memo));

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
  // Implement DFS or BFS here instead of recursion
}

int jump(int y, int x) {
  while (y < Y - 1) {
    y += 2;
    if (data[y][x] == 1)
      break;
    if (data[y][x] == 0)
      return y;
  }
  return (y >= Y - 1) ? -2 : -1;
}