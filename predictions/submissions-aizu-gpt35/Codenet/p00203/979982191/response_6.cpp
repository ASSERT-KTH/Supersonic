#include <iostream>
#include <cstring>
#define N 15
using namespace std;
int jump(int, int);
int X, Y, data[N][N], memo[N][N];
bool visited[N][N];
int dy[3] = {1, 1, 2};
int dx[3] = {-1, 1, 0};
int dfs(int y, int x) {
  if (y == Y - 1) {
    memo[y][x] = 1;
    return 1;
  }
  visited[y][x] = true;
  for (int i = 0; i < 3; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= Y || nx < 0 || nx >= X || data[ny][nx] == 1 || visited[ny][nx])
      continue;
    if (data[ny][nx] == 2) {
      int r = jump(ny, nx);
      if (r != -1)
        memo[y][x] += memo[r][nx] == -1 ? dfs(r, nx) : memo[r][nx];
      else
        memo[y][x] += 1;
    } else {
      if (memo[ny][nx] == -1)
        memo[y][x] += dfs(ny, nx);
      else
        memo[y][x] += memo[ny][nx];
    }
  }
  visited[y][x] = false;
  return memo[y][x];
}
int jump(int y, int x) {
  while (1) {
    y += 2;
    if (y >= Y || data[y][x] == 1)
      return -1;
    if (data[y][x] == 0)
      return y;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    cin >> X >> Y;
    if (X == 0 && Y == 0)
      break;
    memset(memo, -1, sizeof(memo));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < Y; i++)
      for (int j = 0; j < X; j++)
        cin >> data[i][j];
    int cnt = 0;
    for (int i = 0; i < X; i++)
      if (data[0][i] == 0 && memo[0][i] == -1)
        cnt += dfs(0, i);
    cout << cnt << endl;
  }
  return 0;
}