#include <cstdio>
#include <cstring>
#include <queue>
#include <array>
#include <algorithm>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H, sx, sy, gx, gy;
int csize, wsize;
std::array<int, 3> wx, wy, cx, cy;
char field[16][16];
int DP[9][9][9][9][9][9][9][9];

struct state {
  int x, y, Sc;
  std::array<int, 3> cx, cy;
  
  state(int _x, int _y, std::array<int, 3> _cx, std::array<int, 3> _cy, int _Sc) {
    x = _x;
    y = _y;
    Sc = _Sc;
    cx = _cx;
    cy = _cy;
  }
  
  bool operator<(const state &a) const {
    if (x != a.x)
      return x < a.x;
    if (y != a.y)
      return y < a.y;
    if (cx != a.cx)
      return cx < a.cx;
    if (cy != a.cy)
      return cy < a.cy;
    return Sc < a.Sc;
  }
  
  bool operator==(const state &a) const {
    return (x == a.x && y == a.y && cx == a.cx && cy == a.cy && Sc == a.Sc);
  }
};

bool isdel(int tx, int ty, const std::array<int, 3>& ncx, const std::array<int, 3>& ncy) {
  if (field[ty][tx] != 'w')
    return true;
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty)
      return true;
  }
  return false;
}

bool iscontena(int tx, int ty, const std::array<int, 3>& ncx, const std::array<int, 3>& ncy, int Sc) {
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i)))
      return true;
  }
  return false;
}

void BFS(int nx, int ny, const std::array<int, 3>& ncx, const std::array<int, 3>& ncy, int Sc) {
  std::array<std::array<int, 16>, 16> bfscost;
  bfscost.fill(std::array<int, 16>(-1));

  bfscost[ny][nx] = 0;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(nx, ny));

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();

    for (int k = 0; k < 4; k++) {
      int tx = x + dx[k];
      int ty = y + dy[k];

      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 || iscontena(tx, ty, ncx, ncy, Sc))
        continue;

      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy))
        continue;

      bfscost[ty][tx] = cost + 1;
      q.push(std::make_pair(tx, ty));
    }
  }
}

void input() {
  for (int i = 0; i < H; i++) {
    scanf("%s", field[i]);
    for (int j = 0; j < W; j++) {
      if (field[i][j] == '@')
        sx = j, sy = i;
      if (field[i][j] == 'E')
        gx = j, gy = i;
      if (field[i][j] == 'w') {
        wx[wsize] = j, wy[wsize] = i;
        wsize++;
      }
      if (field[i][j] == 'c') {
        cx[csize] = j, cy[csize] = i;
        csize++;
      }
    }
  }
}

int main() {
  while (scanf("%d%d", &H, &W), H | W) {
    csize = wsize = 0;
    std::fill_n(reinterpret_cast<int*>(DP), sizeof(DP) / sizeof(int), -1);
    cx.fill(0);
    cy.fill(0);
    input();
    int res = INT_MAX;
    std::priority_queue<std::pair<int, state>, std::vector<std::pair<int, state>>, std::greater<std::pair<int, state>>> q;
    q.push(std::make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;

    while (!q.empty()) {
      int cost = q.top().first;
      int nx = q.top().second.x;
      int ny = q.top().second.y;
      int tSc = q.top().second.Sc;
      std::array<int, 3> ncx = q.top().second.cx;
      std::array<int, 3> ncy = q.top().second.cy;
      q.pop();

      if (res <= cost)
        break;

      BFS(nx, ny, ncx, ncy, tSc);

      if (bfscost[gy][gx] != -1)
        res = std::min(res, cost + bfscost[gy][gx]);

      for (int i = 0; i < csize; i++) {
        if (!(tSc & (1 << i))) {