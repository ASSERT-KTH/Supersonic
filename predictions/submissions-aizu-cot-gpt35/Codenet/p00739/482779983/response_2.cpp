#include <iostream>
#include <unordered_set>
#include <vector>

typedef long long ll;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int w, h, csize;
int field[12][12], tatu[20][2], kazu[20][2];
std::unordered_set<ll> visited[20][4][2];

bool inside(int x, int y) {
  return !(x < 0 || x >= w || y >= h || y < 0);
}

bool backtrack(int cnt, ll kS, int init_dir, int f) {
  if (visited[cnt][init_dir][f].count(kS))
    return false;
  if (csize / 2 == cnt)
    return true;

  for (int i = 0; i < cnt; i++) {
    for (int k = 0; k < 4; k++) {
      int tx = tatu[i][0] + dx[k];
      int ty = tatu[i][1] + dy[k];
      if (!inside(tx, ty) || field[ty][tx] == 0)
        continue;
      int ttx = kazu[i][0] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu[i][1] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0)
        continue;
      field[ty][tx] = 0;
      tatu[cnt][0] = tx, tatu[cnt][1] = ty;
      field[tty][ttx] = 0;
      kazu[cnt][0] = ttx, kazu[cnt][1] = tty;
      if (backtrack(cnt + 1, kS | (1LL << field[ttx][tty]), init_dir, f))
        return true;
      field[tty][ttx] = 1;
      field[ty][tx] = 1;
    }
  }

  visited[cnt][init_dir][f].insert(kS);
  return false;
}

bool solve() {
  if (csize % 2)
    return false;
  tatu[0][0] = field[0][0], tatu[0][1] = field[0][1];
  field[field[0][1]][field[0][0]] = 0;
  for (int j = 1; j < csize; j++) {
    kazu[0][0] = field[j][0], kazu[0][1] = field[j][1];
    field[field[j][1]][field[j][0]] = 0;
    for (int k = 0; k < 4; k++) {
      if (backtrack(1, 1LL << j, k, 0))
        return true;
      if (backtrack(1, 1LL << j, k, 1))
        return true;
    }
    field[field[j][1]][field[j][0]] = 1;
  }
  field[field[0][1]][field[0][0]] = 1;
  return false;
}

int main() {
  while (std::cin >> w >> h, w | h) {
    csize = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        std::cin >> field[i][j];
        if (field[i][j] == 1) {
          tatu[csize][0] = j, tatu[csize][1] = i;
          field[i][j] = csize;
          csize++;
        }
      }
    }
    std::cout << (solve() ? "YES" : "NO") << std::endl;
  }
  return 0;
}