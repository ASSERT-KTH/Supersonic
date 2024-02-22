#include <cstdio>
#include <cstring>
#include <queue>

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int W, H, sx, sy, gx, gy;
int wsize, csize;
int bfscost[10][10];
char field[16][16];
char DP[9][9][9][9][9][9][9][9];

struct state {
  char x, y, cx[3], cy[3], Sc;
  state(char _x, char _y, char _cx[], char _cy[], char _Sc) {
    x = _x, y = _y, Sc = _Sc;
    memcpy(cx, _cx, sizeof(cx));
    memcpy(cy, _cy, sizeof(cy));
  }
};

bool isdel(char tx, char ty, char ncx[], char ncy[]) {
  if (field[ty][tx] != 'w')
    return true;
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty)
      return true;
  }
  return false;
}

bool iscontena(char tx, char ty, char ncx[], char ncy[], char Sc) {
  for (int i = 0; i < csize; i++) {
    if (ncx[i] == tx && ncy[i] == ty && !(Sc & (1 << i)))
      return true;
  }
  return false;
}

void BFS(char nx, char ny, char ncx[], char ncy[], char Sc) {
  memset(bfscost, -1, sizeof(bfscost));
  bfscost[ny][nx] = 0;
  std::queue<std::pair<int, int>> q;
  q.push(std::make_pair(nx, ny));
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    int cost = bfscost[y][x];
    q.pop();
    for (int k = 0; k < 4; k++) {
      int tx = x + dx[k];
      int ty = y + dy[k];
      if (field[ty][tx] == '#' || bfscost[ty][tx] != -1 ||
          iscontena(tx, ty, ncx, ncy, Sc))
        continue;
      if (field[ty][tx] == 'w' && !isdel(tx, ty, ncx, ncy))
        continue;
      bfscost[ty][tx] = cost + 1;
      q.push(std::make_pair(tx, ty));
    }
  }
}

void input() {
  scanf("%d%d", &H, &W);
  if (H == 0 && W == 0)
    return;
  wsize = csize = 0;
  memset(DP, -1, sizeof(DP));
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
  while (true) {
    input();
    if (H == 0 && W == 0)
      break;

    int res = -1;
    std::priority_queue<std::pair<int, state>> q;
    q.push(std::make_pair(0, state(sx, sy, cx, cy, 0)));
    DP[cx[0]][cy[0]][cx[1]][cy[1]][cx[2]][cy[2]][sx][sy] = 0;
    while (!q.empty()) {
      int cost = q.top().first;
      char nx = q.top().second.x, ny = q.top().second.y;
      char tSc = q.top().second.Sc;
      char ncx[3], ncy[3];
      memcpy(ncx, q.top().second.cx, sizeof(ncx));
      memcpy(ncy, q.top().second.cy, sizeof(ncy));
      q.pop();
      if (res != -1 && cost >= res)
        continue;
      BFS(nx, ny, ncx, ncy, tSc);
      if (bfscost[gy][gx] != -1) {
        res = (res == -1 ? cost + bfscost[gy][gx] : std::min(res, cost + bfscost[gy][gx]));
      }
      for (int i = 0; i < csize; i++) {
        if (!(tSc & (1 << i))) {
          for (int j = 0; j < 4; j++) {
            int tx = ncx[i] + dx[j];
            int ty = ncy[i] + dy[j];
            if (bfscost[ty][tx] == -1)
              continue;
            int ttSc = tSc;
            int dir = (j + 2) % 4;
            int tcx = ncx[i], tcy = ncy[i];
            for (;;) {
              int ay = tcy + dy[dir];
              int ax = tcx + dx[dir];
              if (field[ay][ax] == '#' || iscontena(ax, ay, ncx, ncy, tSc))
                break;