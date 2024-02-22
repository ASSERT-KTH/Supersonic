#include <cstdio>
#include <map>
using namespace std;

#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); it++)
typedef long long ll;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};
int w, h, tatu_x[20], tatu_y[20], kazu_x[20], kazu_y[20];
int field[12][12], cx[36], cy[36], csize;
map<pair<int, int>, int> idx;

bool backtrack(int cnt, ll kS, int init_dir, int f) {
  int i, k;
  if (csize / 2 == cnt)
    return true;
  rep(i, cnt) {
    rep(k, 4) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];
      if (!(tx < 0 || tx >= w || ty >= h || ty < 0) && field[ty][tx] == 1) {
        int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
        int tty = kazu_y[i] + dy[(k + init_dir) % 4];
        if ((tx == ttx && ty == tty) && !(ttx < 0 || ttx >= w || tty >= h || tty < 0) && field[tty][ttx] == 1) {
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
    }
  }
  return false;
}

int main() {
  int i, j, k;
  while (scanf("%d %d", &w, &h), w | h) {
    idx.clear();
    csize = 0;
    rep(i, h) rep(j, w) {
      scanf("%d", &field[i][j]);
      if (field[i][j] == 1) {
        cx[csize] = j, cy[csize] = i;
        idx[make_pair(j, i)] = csize;
        csize++;
      }
    }
    puts(backtrack(0, 0, 0, 0) || backtrack(0, 0, 0, 1) ? "YES" : "NO");
  }
  return 0;
}