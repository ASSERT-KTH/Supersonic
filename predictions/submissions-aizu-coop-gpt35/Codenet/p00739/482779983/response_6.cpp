#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
#define REP(i, a, n) for (int i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) \
  for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[12][12], cx[36], cy[36], csize;
int idx[12][12];
bitset<160> visited;
bool inside(int x, int y) { return x >= 0 && x < w && y >= 0 && y < h; }
bool backtrack(int cnt, ll kS, int init_dir, int f) {
  if (visited[kS])
    return false;
  if (csize / 2 == cnt)
    return true;
  int cnt2 = cnt * 2;
  int cnt2_plus_1 = cnt2 + 1;
  int tatu_x_cnt, tatu_y_cnt, kazu_x_cnt, kazu_y_cnt;
  int tx, ty, ttx, tty;
  rep(i, cnt) {
    tatu_x_cnt = tatu_x[i];
    tatu_y_cnt = tatu_y[i];
    rep(k, 4) {
      tx = tatu_x_cnt + dx[k];
      ty = tatu_y_cnt + dy[k];
      if (!inside(tx, ty) || field[ty][tx] == 0)
        continue;
      ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      tty = kazu_y[i] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0)
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
  visited[kS] = true;
  return false;
}
bool solve() {
  if (csize % 2)
    return false;
  int cx_0, cy_0, cx_j, cy_j;
  cx_0 = cx[0];
  cy_0 = cy[0];
  tatu_x[0] = cx_0, tatu_y[0] = cy_0;
  field[cy_0][cx_0] = 0;
  REP(j, 1, csize) {
    cx_j = cx[j];
    cy_j = cy[j];
    kazu_x[0] = cx_j, kazu_y[0] = cy_j;
    field[cy_j][cx_j] = 0;
    rep(k, 4) {
      if (backtrack(1, 1LL << idx[cx_j][cy_j], k, 0))
        return true;
      if (backtrack(1, 1LL << idx[cx_j][cy_j], k, 1))
        return true;
    }
    field[cy_j][cx_j] = 1;
  }
  field[cy_0][cx_0] = 1;
  return false;
}
int main() {
  while (cin >> w >> h, w | h) {
    visited.reset();
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