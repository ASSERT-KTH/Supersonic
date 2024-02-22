#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x)                                                         \
  for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[12][12], cx[36], cy[36], csize;
int idx[12][12];
bool visited[20][4][2];
bool inside(int x, int y) { return !(x < 0 || x >= w || y >= h || y < 0); }
bool backtrack(int cnt, ll kS, int init_dir, int f) {
  int i, k;
  if (visited[cnt][init_dir][f])
    return false;
  if (csize / 2 == cnt)
    return true;
  rep(i, cnt) {
    rep(k, 4) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
      bool isInside = inside(tx, ty);
      bool isInsideAndOccupied = isInside && field[ty][tx] != 0;
      if (!isInsideAndOccupied)
        continue;
      int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu_y[i] + dy[(k + init_dir) % 4];
      bool isTtxInside = inside(ttx, tty);
      bool isTtxInsideAndOccupied = isTtxInside && field[tty][ttx] != 0;
      bool isSamePos = tx == ttx && ty == tty;
      if (isSamePos || !isTtxInsideAndOccupied)
        continue;
      field[ty][tx] = 0;
      tatu_x[cnt] = tx, tatu_y[cnt] = ty;
      field[tty][ttx] = 0;
      kazu_x[cnt] = ttx, kazu_y[cnt] = tty;
      if (backtrack(cnt + 1, kS | (1LL << idx[ttx][tty]), init_dir, f))
        return true;
      field[tty][ttx] = 1;
      field[ty][tx] = 1;
    }
  }
  visited[cnt][init_dir][f] = true;
  return false;
}
bool solve() {
  int j, k;
  if (csize % 2)
    return false;
  tatu_x[0] = cx[0], tatu_y[0] = cy[0];
  field[cy[0]][cx[0]] = 0;
  REP(j, 1, csize) {
    kazu_x[0] = cx[j], kazu_y[0] = cy[j];
    field[cy[j]][cx[j]] = 0;
    rep(k, 4) {
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
  int i, j;
  while (cin >> w >> h, w | h) {
    rep(i, 20) rep(j, 4) visited[i][j][0] = visited[i][j][1] = false;
    csize = 0;
    rep(i, h) rep(j, w) {
      cin >> field[i][j];
      if (field[i][j] == 1) {
        cx[csize] = j, cy[csize] = i;
        idx[j][i] = csize;
        csize++;
      }
    }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}