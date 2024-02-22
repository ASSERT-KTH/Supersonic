#include <cstdio>
#include <iostream>
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

bool inside(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

bool backtrack(int cnt, ll kS, int init_dir, int f, int w, int h, int tatu_x[], int tatu_y[], 
               int kazu_x[], int kazu_y[], int field[][12], set<ll> visited[][4][2]) {
  if (csize / 2 == cnt)
    return true;
  for(int i = 0; i < cnt; i++) {
    for(int k = 0; k < 4; k++) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
      if (!inside(tx, ty, w, h) || field[ty][tx] == 0)
        continue;
      int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu_y[i] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty, w, h) || field[tty][ttx] == 0)
        continue;
      field[ty][tx] = 0;
      tatu_x[cnt] = tx, tatu_y[cnt] = ty;
      field[tty][ttx] = 0;
      kazu_x[cnt] = ttx, kazu_y[cnt] = tty;
      if (backtrack(cnt + 1, kS | (1LL << idx[make_pair(ttx, tty)]), init_dir, f, w, h, tatu_x, tatu_y, 
                    kazu_x, kazu_y, field, visited))
        return true;
      field[tty][ttx] = 1;
      field[ty][tx] = 1;
    }
  }
  visited[cnt][init_dir][f].insert(kS);
  return false;
}

int main() {
  int w, h;
  int tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
  int field[12][12], cx[36], cy[36], csize;
  int idx[12][12];
  set<ll> visited[20][4][2];
  while (cin >> w >> h, w | h) {
    csize = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cin >> field[i][j];
        if (field[i][j] == 1) {
          cx[csize] = j, cy[csize] = i;
          idx[j][i] = csize;
          csize++;
        }
      }
    }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}