#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
int w, h, Col;
typedef pair<int, int> C;
typedef vector<vector<int>> P;
P V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
P temp;
int tres = 0;
void calc(int y, int x) {
  if (y < 0 || x < 0 || x >= w || y >= h)
    return;
  if (temp[y][x] == Col) {
    tres++;
    temp[y][x] = 0;
    for (int r = 0; r < 4; r++)
      calc(y + dy[r], x + dx[r]);
  }
}
void on(P N, int count, int c) {
  if (count == 5) {
    temp = N;
    tres = 0;
    calc(0, 0);
    res = max(res, tres);
    return;
  }
  int nc = N[0][0];
  queue<C> Q;
  Q.push(make_pair(0, 0));
  bool used[8][8];
  memset(used, false, sizeof(used));
  int tres = 0;
  while (!Q.empty()) {
    C now = Q.front();
    Q.pop();
    if (used[now.first][now.second])
      continue;
    used[now.first][now.second] = c;
    N[now.first][now.second] = c;
    for (int r = 0; r < 4; r++) {
      int ny = now.first + dy[r], nx = now.second + dx[r];
    