#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <bitset>
using namespace std;

#define REP(i, a, n) for (int i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define foreach(it, x) for (auto it = x.begin(); it != x.end(); it++)
#define int long long

const int INF = 1e9;
const int MOD = INF + 7;

typedef long long ll;
typedef pair<int, int> pii;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {-1, 0, 1, 0};

const int MAX_H = 12;
const int MAX_W = 12;
const int MAX_C = 20;

int w, h, tatu_x[MAX_C], tatu_y[MAX_C], kazu_x[MAX_C], kazu_y[MAX_C];
int field[MAX_H][MAX_W], cx[MAX_C], cy[MAX_C], csize;
map<pair<int, int>, int> idx;
bitset<1<<20> visited[20][4][2];

bool inside(int x, int y) { return !(x < 0 || x >= w || y >= h || y < 0); }

bool backtrack(int cnt, int kS, int init_dir, int f) {
  if (visited[cnt][init_dir][f][kS]) {
    return false;
  }

  if (csize / 2 == cnt) {
    return true;
  }

  visited[cnt][init_dir][f][kS] = true;

  rep(i, cnt) {
    rep(k, 4) {
      int tx = tatu_x[i] + dx[k];
      int ty = tatu_y[i] + dy[k];

      if (!inside(tx, ty) || field[ty][tx] == 0) {
        continue;
      }

      int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
      int tty = kazu_y[i] + dy[(k + init_dir) % 4];

      if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0) {
        continue;
      }

      field[ty][tx] = 0;
      tatu_x[cnt] = tx, tatu_y[cnt] = ty;
      field[tty][ttx] = 0;
      kazu_x[cnt] = ttx, kazu_y[cnt] = tty;

      if (backtrack(cnt + 1, kS | (1LL << idx[make_pair(ttx, tty)]), k, f)) {
        return true;
      }

      field[tty][ttx] = 1;
      field[ty][tx] = 1;
    }
  }

  return false;
}

bool solve() {
  tatu_x[0] = cx[0], tatu_y[0] = cy[0];
  field[cy[0]][cx[0]] = 0;

  REP(j, 1, csize) {
    kazu_x[0] = cx[j], kazu_y[0] = cy[j];
    field[cy[j]][cx[j]] = 0;

    rep(k, 4) {
      if (backtrack(1, 1LL << j, k, 0) || backtrack(1, 1LL << j, k, 1)) {
        return true;
      }
    }

    field[cy[j]][cx[j]] = 1;
  }

  field[cy[0]][cx[0]] = 1;

  return false;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (cin >> w >> h, w | h) {
    idx.clear();
    rep(i, 20) rep(j, 4) rep(k, 2) visited[i][j][k].reset();

    csize = 0;

    rep(i, h) rep(j, w) {
      cin >> field[i][j];

      if (field[i][j] == 1) {
        cx[csize] = j, cy[csize] = i;
        idx[make_pair(j, i)] = csize;
        csize++;
      }
    }

    puts(solve() ? "YES" : "NO");
  }

  return 0;
}