#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
int w, h, csize;
int field[12][12], cx[36], cy[36];
unordered_map<int, int> idx;
unordered_set<ll> visited[20][4][2];
inline bool inside(int x, int y) { return !(x < 0 || x >= w || y >= h || y < 0); }
bool backtrack(int cnt, ll kS, int init_dir, int f) {
  if (visited[cnt][init_dir][f].count(kS))
    return false;
  if (csize / 2 == cnt)
    return true;
  for (int i = 0; i < cnt; ++i) {
    for (int k = 0; k < 4; ++k) {
      static const int dx[] = {0, 1, 0, -1};
      static const int dy[] = {-1, 0, 1, 0};
      int tx = cx[i] + dx[k];
      int ty = cy[i] + dy[k];
      if (!inside(tx, ty) || field[ty][tx] == 0)
        continue;
      int ttx = cx[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = cy[i] + dy[(k + init_dir) % 4];
      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0)
        continue;
      field[ty][tx] = field[tty][ttx] = 0;
      int old_cx = cx[cnt], old_cy = cy[cnt];
      cx[cnt] = tx, cy[cnt] = ty;
      if (backtrack(cnt + 1, kS | (1LL << idx[ttx*12 + tty]), init_dir, f))
        return true;
      field[tty][ttx] = field[ty][tx] = 1;
      cx[cnt] = old_cx, cy[cnt] = old_cy;
    }
  }
  visited[cnt][init_dir][f].insert(kS);
  return false;
}
bool solve() {
  if (csize % 2)
    return false;
  for (int j = 1; j < csize; ++j) {
    field[cy[0]][cx[0]] = field[cy[j]][cx[j]] = 0;
    int old_cx = cx[0], old_cy = cy[0];
    cx[0] = cx[j], cy[0] = cy[j];
    for (int k = 0; k < 4; ++k) {
      if (backtrack(1, 1LL << j, k, 0) || backtrack(1, 1LL << j, k, 1))
        return true;
    }
    field[cy[0]][cx[0]] = field[cy[j]][cx[j]] = 1;
    cx[0] = old_cx, cy[0] = old_cy;
  }
  return false;
}
int main() {
  while (cin >> w >> h, w | h) {
    idx.clear();
    for (int i = 0; i < 20; ++i)
      for (int j = 0; j < 4; ++j)
        visited[i][j][0].clear(), visited[i][j][1].clear();
    csize = 0;
    for (int i = 0; i < h; ++i)
      for (int j = 0; j < w; ++j) {
        cin >> field[i][j];
        if (field[i][j] == 1) {
          cx[csize] = j, cy[csize] = i;
          idx[j*12 + i] = csize;
          ++csize;
        }
      }
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}