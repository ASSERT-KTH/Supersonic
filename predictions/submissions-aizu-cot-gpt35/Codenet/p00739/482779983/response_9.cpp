#include <iostream>
#include <map>
#include <set>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[12][12], cx[36], cy[36], csize;
map<pair<int, int>, int> idx;
set<ll> visited;

bool inside(int x, int y) {
  return x >= 0 && x < w && y >=0 && y < h;
}

bool backtrack(int cnt, ll kS, int init_dir, int f) {
  if (visited.count(kS))
    return false;
  if (csize / 2 == cnt)
    return true;
  for (int i = 0; i < cnt; i++) {
    for (int k = 0; k < 4; k++) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
      if (!inside(tx, ty) || field[ty][tx] == 0)
        continue;
      int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu_y[i] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0)
        continue;
      field[ty][tx] = 0;
      tatu_x[cnt] = tx, tatu_y[cnt] = ty;
      field[tty][ttx] = 0;
      kazu_x[cnt] = ttx, kazu_y[cnt] = tty;
      if (backtrack(cnt + 1, kS | (1LL << idx[make_pair(ttx, tty)]), init_dir, f))
        return true;
      field[tty][ttx] = 1;
      field[ty][tx] = 1;
    }
  }
  visited.insert(kS);
  return false;
}

bool solve() {
  tatu_x[0] = cx[0], tatu_y[0] = cy[0];
  field[cy[0]][cx[0]] = 0;
  for (int j = 1; j < csize; j++) {
    kazu_x[0] = cx[j], kazu_y[0] = cy[j];
    field[cy[j]][cx[j]] = 0;
    for (int k = 0; k < 4; k++) {
      if (backtrack(1, 1LL << j, k, 0))
        return true;
      if (backtrack(1, 1LL << j, k, 1))
        return true;
    }
    field[cy[j]][cx[j]] = 1;
  }
  field[cy[0]][cx[0]] = 1;
  return false;
}

int main() {
  while (cin >> w >> h, w | h) {
    idx.clear();
    visited.clear();
    csize = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> field[i][j];
        if (field[i][j] == 1) {
          cx[csize] = j, cy[csize] = i;
          idx[make_pair(j, i)] = csize;
          csize++;
        }
      }
    }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}