#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> P;

const int MAX_RC = 1005;
const int INF = 1 << 30;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int R, C, d[MAX_RC][MAX_RC];
char field[MAX_RC][MAX_RC];

void dijkstra(int sx, int sy) {
  priority_queue<P, vector<P>, greater<P>> q;
  fill((int*)d, (int*)d + MAX_RC * MAX_RC, INF);
  d[sx][sy] = 0;
  q.push(P(0, sx * MAX_RC + sy));
  while (!q.empty()) {
    P p = q.top(); q.pop();
    int x = p.second / MAX_RC, y = p.second % MAX_RC;
    if (d[x][y] < p.first) continue;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir], ny = y + dy[dir];
      if (nx >= 0 && nx < R && ny >= 0 && ny < C && field[nx][ny] != '#') {
        int cost = field[nx][ny] == 'x' ? 2 : 1;
        if (d[nx][ny] > d[x][y] + cost) {
          d[nx][ny] = d[x][y] + cost;
          q.push(P(d[nx][ny], nx * MAX_RC + ny));
        }
      }
    }
  }
}

int main() {
  scanf("%d %d", &R, &C);
  int sx, sy, gx, gy;
  for (int i = 0; i < R; ++i) {
    scanf("%s", field[i]);
    for (int j = 0; j < C; ++j) {
      if (field[i][j] == 'S') sx = i, sy = j;
      if (field[i][j] == 'G') gx = i, gy = j;
    }
  }
  dijkstra(sx, sy);
  printf("%d\n", d[gx][gy]);
  return 0;
}